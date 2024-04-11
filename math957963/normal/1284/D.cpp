#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD1 998244353
#define MOD2 993244853
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000






int main() {
	vector<long long>ar1;
	vector<long long>al1;
	vector<long long>br1;
	vector<long long>bl1;
	vector<long long>ar2;
	vector<long long>al2;
	vector<long long>br2;
	vector<long long>bl2;
	vector<long long>c1;
	vector<long long>c2;
	c1.push_back(61);
	c2.push_back(83);
	long long rr;
	f(i, N) {
		rr = c1[i];
		rr = (rr * 89) % MOD1;
		c1.push_back(rr);
	}
	f(i, N) {
		rr = c2[i];
		rr = (rr * 73) % MOD2;
		c2.push_back(rr);
	}
	vector<int>a;
	vector<int>b;
	vector<int>ax;
	vector<int>ay;
	vector<int>bx;
	vector<int>by;
	vector<pair<int, int> >sax;
	vector<pair<int, int> >say;
	vector<pair<int, int> >sbx;
	vector<pair<int, int> >sby;
	int n, k, kk;
	int x, y,xx,yy, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		ax.push_back(x);
		ay.push_back(y);
		bx.push_back(xx);
		by.push_back(yy);
		sax.push_back(make_pair(x, i));
		say.push_back(make_pair(y, i));
		sbx.push_back(make_pair(xx, i));
		sby.push_back(make_pair(yy, i));
	}
	sax.push_back(make_pair(-1, -1));
	say.push_back(make_pair(-1, -1));
	sbx.push_back(make_pair(-1, -1));
	sby.push_back(make_pair(-1, -1));
	sax.push_back(make_pair(1000000007, -1));
	say.push_back(make_pair(1000000007, -1));
	sbx.push_back(make_pair(1000000007, -1));
	sby.push_back(make_pair(1000000007, -1));
	sort(sax.begin(), sax.end());
	sort(say.begin(), say.end());
	sort(sbx.begin(), sbx.end());
	sort(sby.begin(), sby.end());
	rr = 0;
	ar1.push_back(0);
	f(i, n) {
		rr = (rr + c1[say[i + 1].second]);
		ar1.push_back(rr);
	}
	ar1.push_back(rr);
	rr = 0;
	ar2.push_back(0);
	f(i, n) {
		rr = (rr + c2[say[i + 1].second]);
		ar2.push_back(rr);
	}
	ar2.push_back(rr);
  rr=0;
	br1.push_back(0);
	f(i, n) {
		rr = (rr + c1[sby[i + 1].second]);
		br1.push_back(rr);
	}
	br1.push_back(rr);
	rr = 0;
	br2.push_back(0);
	f(i, n) {
		rr = (rr + c2[sby[i + 1].second]);
		br2.push_back(rr);
	}
	br2.push_back(rr);
	rr = 0;
	f(i, n) {
		rr = (rr + c1[sax[i + 1].second]);
	}
	al1.push_back(rr);
	al1.push_back(rr);
	f(i, n) {
		rr = (rr - c1[sax[i + 1].second]);
		al1.push_back(rr);
	}
	rr = 0;
	f(i, n) {
		rr = (rr + c2[sax[i + 1].second]);
	}
	al2.push_back(rr);
	al2.push_back(rr);
	f(i, n) {
		rr = (rr - c2[sax[i + 1].second]);
		al2.push_back(rr);
	}
	rr = 0;
	f(i, n) {
		rr = (rr + c1[sbx[i + 1].second]);
	}
	bl1.push_back(rr);
	bl1.push_back(rr);
	f(i, n) {
		rr = (rr - c1[sbx[i + 1].second]);
		bl1.push_back(rr);
	}
	rr = 0;
	f(i, n) {
		rr = (rr + c2[sbx[i + 1].second]);
	}
	bl2.push_back(rr);
	bl2.push_back(rr);
	f(i, n) {
		rr = (rr - c2[sbx[i + 1].second]);
		bl2.push_back(rr);
	}


	int l, r, m;
	k = 0;
	kk = 0;
	z = 0;
	f(i, n) {
		s = 0;
		ans = 0;
		l = 0;
		r = n + 2;
		while ((l + 1) < r) {
			m = (l + r) / 2;
			if (say[m].first < ax[i])l = m;
			else r = m;
		}
		s += ar1[l];
		ans += ar2[l];
		l = 0;
		r = n + 2;
		while ((l + 1) < r) {
			m = (l + r) / 2;
			if (sax[m].first <= ay[i])l = m;
			else r = m;
		}
		s += al1[r];
		ans += al2[r];

		l = 0;
		r = n + 2;
		while ((l + 1) < r) {
			m = (l + r) / 2;
			if (sby[m].first < bx[i])l = m;
			else r = m;
		}
		s -= br1[l];
		ans -= br2[l];
		l = 0;
		r = n + 2;
		while ((l + 1) < r) {
			m = (l + r) / 2;
			if (sbx[m].first <= by[i])l = m;
			else r = m;
		}
		s -= bl1[r];
		ans -= bl2[r];
		if ((s != 0) || (ans != 0)) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");


	return 0;
}
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
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200010


int main() {
	map<long long, long long>xx;
	map<long long, long long>yy;
	vector<long long>cx;
	vector<long long>cy;
	vector<pair<long long, long long> >p;
	long long n, m, h;
	long long x, y, z, w;
	long long kx, ky;
	long long s,ss, ans;
	long long xc[N];
	long long xxc[500];
	vector<int>v;
	long long dp[N];
	long long yx[N];
	long long befyx[N];
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d %I64d", &x, &y);
		p.push_back(make_pair(x, y));
		cx.push_back(x);
		cy.push_back(y);
	}
	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());
	x = 0;
	y = 0;
	f(i, n) {
		if (i == 0) {
			xx[cx[i]] = x;
			yy[cy[i]] = y;
			x++;
			y++;
		}
		else {
			if (cx[i] != cx[i - 1]) {
				xx[cx[i]] = x;
				x++;
			}
			if (cy[i] != cy[i - 1]) {
				yy[cy[i]] = y;
				y++;
			}
		}
	}
	kx = x;
	ky = y;
	f(i, N)xc[i] = 0;
	f(i, n) {
		p[i].first = xx[(p[i].first)];
		p[i].second = yy[(p[i].second)];
		xc[p[i].first]++;
		swap(p[i].second, p[i].first);
	}
	sort(p.begin(), p.end());
	f(i, 500)xxc[i] = 0;
	f(i, kx)xxc[(i / 500)]++;
	x = 0;
	ans = 0;
	f(i, ky) {
		v.clear();
		v.push_back(-1);
		if (x < n) {
			while (p[x].first == i) {
				v.push_back(p[x].second);
				xc[p[x].second]--;
				if (xc[p[x].second] == 0)xxc[(p[x].second / 500)]--;
				x++;
				if (x >= n)break;
			}
		}
		v.push_back(kx);
		s = v.size() - 2;
		ss = 0;
		f(j, v.size() - 1) {
			if (v[j] < 0)y = -1;
			else y = v[j] / 500;
			z = v[j + 1] / 500;
			w = 0;
			if (y+1 >= z) {
				for (int ii = v[j] + 1; ii < v[j + 1]; ii++) {
					if (xc[ii] > 0)w++;
				}
			}
			else {
				for (int ii = v[j] + 1; ii < (y+1)*500; ii++) {
					if (xc[ii] > 0)w++;
				}
				for (int ii = z*500; ii < v[j + 1]; ii++) {
					if (xc[ii] > 0)w++;
				}
				for (int ii = y + 1; ii < z; ii++)w += xxc[ii];
			}
			s += w;
			w = w * (w + 1);
			w = w / 2;
			ss -= w;
		}

		s = s * (s + 1);
		s = s / 2;
		ss += s;
		ans += ss;
	}
	printf("%I64d\n", ans);
	return 0;
}
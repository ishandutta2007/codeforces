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
using namespace std;
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (1<<18)
long long a[(2 * N)];
long long laz[(2 * N)];
int l[(2 * N)];
int r[(2 * N)];

//
void init(void){
	f(i, (2*N)){
		a[i] = -1000000000000;
		laz[i] = 0;
	}
	l[1] = 0;
	r[1] = N;
	for (int i = 1; i<N; i++){
		l[(2 * i)] = l[i];
		r[(2 * i)] = (l[i] + r[i]) / 2;
		l[(2 * i) + 1] = (l[i] + r[i]) / 2;
		r[(2 * i) + 1] = r[i];
	}
	return;
}




long long add(int ll, int rr, int k, long long x){
	long long vl, vr;
	if ((rr <= l[k]) || (r[k] <= ll))return a[k];
	else if (ll <= l[k] && r[k] <= rr){
		laz[k] += x;
		return (a[k] + laz[k]);
	}
	else{
		int mm = (l[k] + r[k]) / 2;
		if (l[k] < rr&&ll < mm){
			vl = add(ll, rr, 2 * k, x);
		}
		else vl = a[(2*k)]+laz[(2*k)];

		if (mm < rr&&ll < r[k]){
			vr = add(ll, rr, (2 * k) + 1, x);
		}
		else vr = a[(2*k)+1]+laz[(2*k)+1];

		a[k] = max(vl,vr);
		return (a[k]+laz[k]);
	}
}


//(0<=l<r<=n)(l<=x<r)(l,r,0)
long long max_search(int ll, int rr, int k){
	if (laz[k] > 0){
		a[k] += laz[k];
		int mm = (l[k] + r[k]) / 2;
		if (k < N){
			laz[(2 * k)] += laz[k];
			laz[(2 * k) + 1] += laz[k];
		}
		laz[k] = 0;
	}
	long long vl, vr;
	if (rr <= l[k] || r[k] <= ll)return -1000000000000000000;
	else if (ll <= l[k] && r[k] <= rr) return a[k];
	else{
		vl = max_search(ll, rr, 2 * k);
		vr = max_search(ll, rr, (2 * k) + 1);
		a[k] = max(a[(2 * k)], a[(2 * k) + 1]);
		return max(vl,vr);
	}
}


int main(void){
	int q;
	int c, x, y;
	long long z;
	vector<pair<int, long long> >aa;
	vector<pair<int, long long> >bb;
	vector<pair<pair<int, int>,long long > >cc;
	int na, nb, nc;
	scanf("%d %d %d", &na, &nb, &nc);
	f(i, na) {
		scanf("%d %lld", &x, &z);
		aa.push_back(make_pair(x, z));
	}
	f(i, nb) {
		scanf("%d %lld", &x, &z);
		bb.push_back(make_pair(x, z));
	}
	f(i, nc) {
		scanf("%d %d %lld", &x, &y, &z);
		cc.push_back(make_pair(make_pair(x, y), z));
	}
	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());
	sort(cc.begin(), cc.end());
	aa.push_back(make_pair(1000001000, 1000000000000000));
	bb.push_back(make_pair(1000001000, 1000000000000000));
	cc.push_back(make_pair(make_pair(1000000100, 1000000100), 0));
	init();
	f(i, nb+1) {
		add(i, i + 1, 1, 1000000000000-bb[i].second);
	}
	long long ans = -100000000000000000;
	long long s;
	int xa = 0;
	int xc = 0;
	int xl, xr, xm;

	while ((xa < na) || (xc < nc)) {
		if ((cc[xc].first.first) < (aa[xa].first)) {
			xl = -1;
			xr = nb;
			while ((xl + 1) < xr) {
				xm = (xl + xr) / 2;
				if ((cc[xc].first.second) >= (bb[xm].first))xl = xm;
				else xr = xm;
			}
			add(xr, nb, 1, cc[xc].second);
			xc++;
		}
		else {
			s = max_search(0, nb,1);
			ans = max(ans, s - aa[xa].second);
			xa++;
		}

	}
	printf("%lld\n", ans);
	return 0;
}
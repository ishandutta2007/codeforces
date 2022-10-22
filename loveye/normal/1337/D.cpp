#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define int long long
#define lb(b,e,x) lower_bound(b,e,x)
#define ub(b,e,x) upper_bound(b,e,x)
int a,b,c,d1[N],d2[N],d3[N],x,y,z,p,q,ans;
inline int pw2(int x) {
	return x * x;
}
inline void check(int x,int y,int z) {
	ans = min(ans,pw2(x-y) + pw2(y-z) + pw2(z-x));
}
inline int myfind(int l,int r,int *a) {
	double mid = (l +r) / 2.;
	int res = lb(a+1,a+a[0]+1,(int)mid) - a;
	int res1,res2;
	if(res == a[0]+1) res2 = -2e9,res1 = a[res-1];
	else if(res == 1) res1 = -2e9,res2 = a[res];
	else res1 = a[res-1],res2 = a[res];
	if(!(l <= res1 && res1 <= r) && !(l <= res2 && res2 <= r)) return -1;
	if(fabs(res1 - mid) < fabs(res2 - mid)) return res1;
	return res2;
}
inline void solve(int *a,int *b,int *c) {
	int n1 = a[0],n2 = b[0],n3 = c[0],r = 1,mid = -1;
	for(int l = 1;l <= n1;++l) {
		while(r <= n2 && b[r] < a[l]) ++r;
		while(r <= n2 && (mid = myfind(a[l],b[r],c)) == -1) ++r;
		if(r > n2 || mid == -1) break;
		check(a[l],b[r],mid);
	}
}
signed main() {
	int t;scanf("%lld",&t);
	while(t--) {
		scanf("%lld%lld%lld",&a,&b,&c);
		for(int i = 1;i <= a;++i)
			scanf("%lld",d1+i);
		for(int i = 1;i <= b;++i)
			scanf("%lld",d2+i);
		for(int i = 1;i <= c;++i)
			scanf("%lld",d3+i);
		d1[0] = a,d2[0] = b,d3[0] = c;
		sort(d1+1,d1+a+1);
		sort(d2+1,d2+b+1);
		sort(d3+1,d3+c+1);
		ans = 4e18;
		solve(d1,d2,d3);
		solve(d1,d3,d2);
		solve(d2,d1,d3);
		solve(d2,d3,d1);
		solve(d3,d2,d1);
		solve(d3,d1,d2);
		printf("%lld\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

const int S = 1 << 21;
char p0[S],*p1,*p2;
#ifndef ZXY
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
#endif
inline int read() {
	static int x,c;x = 0;
	do{c = getchar();}while(!isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();}while(isdigit(c));
	return x;
}

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &

const int N = 1005;
int n,x,pos,ans1,ans2;
int a[N];
inline LL A(int n,int m) {
	LL res = 1;
	for(int i = 0;i < m;++i)
		res = res * (n-i) % MOD;
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> x >> pos;
	int l = 0,r = n;
	while(l < r) {
		int mid = l + r >> 1;
		if(mid <= pos) a[mid] = 1,l = mid+1;
		else r = mid,a[mid] = 2;
	}
	for(int i = 0;i < n;++i) {
		if(a[i] == 1 && i != pos) ++ans1;
		else if(a[i] == 2) ++ans2;
	}
	printf("%lld\n",A(x-1,ans1) * A(n-x,ans2) % MOD * A(n-ans1-ans2-1,n-ans1-ans2-1) % MOD);
	return 0;
}
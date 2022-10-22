#include<bits/stdc++.h>
using namespace std;
const int MOD = 0;

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

int T;
LL p,q,ans;
vector<int> fac;
inline LL qpow(LL a,int x) {
	LL res = 1;
	for(;x;x >>= 1) (x & 1) && (res = res * a),a = a * a;
	return res;
}
inline void reduce(LL x,LL p,LL c) {
	LL res = 0;
	while(x % p == 0) x /= p,++res;
	ans = max(ans, x * qpow(p,c-1));
}
inline void divide(LL x) {
	LL sx = sqrt(x);
	for(int i = 2;i <= sx;++i)
		if(x % i == 0) {
			int res = 0;
			do x /= i,++res; while(x % i == 0);
			reduce(::p,i,res);
		}
	if(x != 1) reduce(::p,x,1);
}
int main() {
	cin >> T;
	while(T--) {
		cin >> p >> q;
		if(p % q) {
			cout << p << endl;
			continue;
		}
		ans = 0;
		divide(q);
		cout << ans << endl;
	}
	return 0;
}
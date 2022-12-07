// LUOGU_RID: 95345155
#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int read() {
	int x=0,w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {x=x*10+c-'0'; c=getchar();}
	return x*w;
}

int T,n,m;

map<pii,int>f;

#define bp __builtin_parity
int dp(int n,int m) {
	if(m==1) return bp(n);
	if(n==0) return 0;
	if(f.count(pii(n,m))) return f[pii(n,m)];
	if(n%2) {
		f[pii(n,m)]=m-dp(n/2,(m+1)/2)-dp((n+1)/2,m/2);
	} else {
		f[pii(n,m)]=dp(n/2,(m+1)/2)+dp(n/2,m/2);
	}
	return f[pii(n,m)];
}

signed main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		printf("%lld\n",dp(n,m));
	}
	return 0;
}
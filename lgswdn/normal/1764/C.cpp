#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define eb emplace_back
#define bp __builtin_parity
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int read() {
	int x=0,w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {x=x*10+c-'0'; c=getchar();}
	return x*w;
}

const int N=1e6+9;

int T,n,a[N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a[i]=read();
		sort(a+1,a+n+1);
		if(a[1]==a[n]) {
			printf("%lld\n",n/2);
			continue;
		}
		int ans=0;
		rep(i,1,n) if(a[i]!=a[i+1]) { 
			ans=max(ans,i*(n-i));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
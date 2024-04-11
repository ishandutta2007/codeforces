#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=2e5+9,mod=998244353;
int T,n,a[N],s[N];

unordered_map<int,int>f[2];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) a[i]=read();
		int ans=0; f[1].clear();
		per(i,n,1) {
			swap(f[0],f[1]); f[1].clear();
			for(auto p:f[0]) {
				ans=(ans+p.se*i%mod*((a[i]-1)/p.fi)%mod)%mod;
				(f[1][(a[i])/((a[i]-1)/p.fi+1)]+=p.se)%=mod;
			}
			f[1][a[i]]++;
		} printf("%lld\n",ans);
	}
	return 0;
}
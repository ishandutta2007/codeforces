#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9,mod=1e9+7;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,s[N],g[N],f[N],sum,ans;
vector<int>e[N];

signed main() {
	n=read();
	rep(i,1,n) s[i]=read(), sum+=s[i];
	rep(i,2,n) e[read()].push_back(i);
	per(i,n,1) {
		for(auto j:e[i]) s[i]+=s[j];
		int p=sum/__gcd(s[i],sum);
		for(int j=p;j<=n;j+=p) g[j]++;
	}
	f[1]=1;
	rep(i,1,n) if(g[i]==i) {
		ans=(ans+f[i])%mod;
		for(int j=2*i;j<=n;j+=i) f[j]=(f[j]+f[i])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
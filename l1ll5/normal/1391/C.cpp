#include <bits/stdc++.h>
#define N 2000005
#define ll long long
#define int long long
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n;
int fac[N];
int inv[N];
inline int Pow(int a, ll b) {
	int res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = (ll)res * a % mod;
		a = (ll)a * a % mod;
	}
	return res;
}
int C(int a,int b){
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
main()
{
    n=read();fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    inv[n]=Pow(fac[n],mod-2);
    for(int i=n;i>=1;i--) inv[i-1]=inv[i]*i%mod;

    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=C(n-1,i-1);
        ans%=mod;
    }
    ans=fac[n]-ans;
    ans%=mod;
    ans+=mod; ans%=mod;
    cout<<ans<<endl;
}
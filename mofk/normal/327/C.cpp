#include<cstdio>
#include<cassert>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstring>
#define f(i,n) for(int i=1;i<=n;i++)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define F(i,n) for (int i=n;i>=1;i--)
#define FF(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define B 1
#define W -1
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int MAX=100005; const ll mod=1000000007;

char s[MAX];
ll k;

ll pwr(ll a,ll b)
{
    ll res=1,mult=a,k=b;
    while(k)
    {
        if(k&1) res=(res*mult)%mod;
        mult=(mult*mult)%mod;
        k>>=1;
    }
    return res;
}

int main(void)
{
    ll ans=0;
    scanf("%s%I64d",s,&k);
    ll l=strlen(s);
    ff(i,0,l-1) if(s[i]=='0'||s[i]=='5')
    {
        ll tmp=(mod+pwr(2,k*l)-1)%mod,tmp2=(mod+pwr(2,l)-1)%mod;
        tmp=(tmp*pwr(tmp2,mod-2))%mod;
        tmp=(tmp*pwr(2,i))%mod;
        ans=(ans+tmp)%mod;
    }
    printf("%I64d",ans);
    return 0;
}
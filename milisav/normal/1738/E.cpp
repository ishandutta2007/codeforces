#include<bits/stdc++.h>
#define maxn 200000
#define mod 998244353
using namespace std;

inline long long step(long long x,long long y) {
    long long ret=1;
    while(y>0) {
        if(y%2==1) ret=(ret*x)%mod;
        x=(x*x)%mod;
        y=y/2;
    }
    return ret;
}
inline long long inv(long long x) {
    return step(x,mod-2);
}
int t;
int n,k;
int a[maxn];
long long s[maxn];
long long fact[maxn];
long long invfact[maxn];
inline long long binom(int n,int k) {
    if(k<0 || k>n) return 0;
    return (((fact[n]*invfact[k])%mod)*invfact[n-k])%mod;
}
int main() {
    fact[0]=invfact[0]=1;
    for(int i=1;i<maxn;i++) {
        fact[i]=(i*fact[i-1])%mod;
        invfact[i]=inv(fact[i]);
    }
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
        }
        long long tot=s[n];
        int p=1;
        int q=n-1;
        long long ans=1;
        while(p<q) {
            if(s[p]+s[q]>tot) q--;
            else {
                if(s[p]+s[q]<tot) p++;
                else {
                    int l=1;
                    int r=1;
                    if(s[p]==s[q]) {
                        int tt=q-p+1;
                        long long cur=0;
                        for(int i=0;i<=tt;i++) {
                            cur=(cur+binom(tt,i))%mod;
                        }
                        ans=(ans*cur)%mod;
                        break;
                    }
                    else {
                        while(s[p+1]==s[p]) {
                            p++;
                            l++;
                        }
                        while(s[q-1]==s[q]) {
                            q--;
                            r++;
                        }
                        p++;
                        q--;
                        long long cur=0;
                        for(int i=0;i<=min(l,r);i++) {
                            cur=(cur+binom(l,i)*binom(r,i))%mod;
                        }
                        ans=(ans*cur)%mod;
                    }
                }
            }
        }
        if(p==q && s[p]+s[q]==tot) ans=(ans*2)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
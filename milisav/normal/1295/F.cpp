#include<bits/stdc++.h>
#define maxn 400
using namespace std;
long long mod = 998244353ll;
long long step(long long a,long long b) {
    if(b==0ll) return 1ll;
    if(b&1ll) return (a*step(a,b-1ll))%mod;
    else return step((a*a)%mod,b>>1ll);
}
long long inverse(long long a) {
    return step(a,mod-2);
}
set<int> p;
set<int>::iterator it;
int n;
int l[maxn],r[maxn];
int ins[10*maxn];
long long dp[maxn][10*maxn];
long long sum[maxn][10*maxn];
long long fact[maxn];
long long invfact[maxn];
long long inv[maxn];
long long select(long long n,long long t) {
    long long s=0;
    long long d=1;
    for(long long i=1;i<=min(t,n);i++) {
        long long b=(((fact[t-1]*invfact[t-i])%mod)*invfact[i-1])%mod;
        d=d*(n-i+1);
        d%=mod;
        d=d*inv[i];
        d%=mod;
        //cout<<i<<" "<<b<<" "<<d<<" "<<t<<" "<<n<<endl;
        s=(s+b*d)%mod;
    }
    return s;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d %d",&l[n-i+1],&r[n-i+1]);
        p.insert(l[n-i+1]);
        p.insert(r[n-i+1]+1);
    }
    fact[0]=invfact[0]=1;
    for(int i=1;i<maxn;i++) {
        fact[i]=(fact[i-1]*i)%mod;
        invfact[i]=inverse(fact[i]);
        inv[i]=inverse(i);
    }
    it=p.begin();
    sum[0][0]=1;
    for(int i=1;i<=n;i++) {
        it=p.begin();
        for(int j=1;it!=p.end();j++,it++) {
            int x=(*it);
            if(l[i]<=x && x<=r[i]) {
                it++;
                int y=(*it);
                ins[j]++;
                for(int k=0;k<j;k++) {
                    for(int t=1;t<=ins[j];t++) {
                        //cout<<i<<" "<<x<<" "<<y<<" "<<t<<" "<<sum[i-t][k]<<" "<<select(y-x,t)<<endl;
                        sum[i][j]=(sum[i][j]+select(y-x,t)*sum[i-t][k])%mod;
                    }
                }
                it--;
            }
            else ins[j]=0;
        }
    }
    it=p.begin();
    long long tot=0;
    for(int j=1;it!=p.end();j++,it++) {
        tot+=sum[n][j];
        //cout<<j<<" "<<sum[n][j]<<" "<<sum[n-1][j]<<" "<<sum[n-2][j]<<endl;
    }
    //cout<<tot<<endl;
    tot%=mod;
    for(int i=1;i<=n;i++) {
        tot=(tot*inverse(r[i]-l[i]+1))%mod;
    }
    printf("%lld",tot);
    return 0;
}
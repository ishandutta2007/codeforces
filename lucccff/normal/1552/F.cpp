#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,ans=0;
    long long a[200010],b[200010],c[200010],d[200010],e[200010],f[200010],g[200010];
    pair <long long,long long> p[200010];
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i]>>b[i]>>c[i];
        p[i]=make_pair(b[i],i);
    }
    sort(p,p+n);
    k=0;
    for(i=0;i<n;i++) {
        while(p[i].first>a[k]) k++;
        e[p[i].second]=k;
        b[p[i].second]=a[k]-b[p[i].second];
    }
    d[0]=a[0];
    for(i=1;i<n;i++) d[i]=a[i]-a[i-1];
    d[n]=1;
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    a[n-1]=1;
    for(i=n-1;i>0;i--) {
        g[e[i]]=(g[e[i]]+a[i]-1+c[i])%MOD;
        if (g[e[i]]<0) g[e[i]]+=MOD;
        a[i-1]=(2*a[i]-1+c[i]-g[i])%MOD;
        if (a[i-1]<0) a[i-1]+=MOD;
    }
    ans=d[0];
    for(i=0;i<n;i++) {
        ans=(ans+d[i+1]*a[i]%MOD+b[i]*(a[i]-1+c[i])%MOD)%MOD;
        if (ans<0) ans+=MOD;
    }
    cout<<ans;
    return 0;
}
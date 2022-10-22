#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n;
int x[maxn];
int y[maxn];
int s[maxn];
long long v[maxn];
int pr[maxn];
long long mod=998244353;
long long sm=0;
long long inv2=(mod+1)/2;
vector<pair<int,int> > a;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d %d",&x[i],&y[i],&s[i]);
    for(int i=1;i<=n;i++) {
        a.push_back({x[i],i});
        a.push_back({y[i],i});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int j=0;j<a.size();j++) {
        int i=a[j].second;
        if(a[j].first==x[i]) {
            v[i]=s[i]+sm;
            sm=(sm+v[i])%mod;
        }
        else {
            sm=(sm+mod-v[i])%mod;
        }
    }
    long long ans=(x[n]+1);
    for(int i=1;i<=n;i++) {
        ans=(ans+v[i]*(x[i]-y[i]))%mod;
    }
    printf("%lld",ans);
    return 0;
}
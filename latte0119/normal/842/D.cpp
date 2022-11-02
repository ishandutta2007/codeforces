#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int SEG=1<<19;
int sum[SEG*2];

signed main(){
    int n,m;scanf("%lld%lld",&n,&m);
    vint a(n);rep(i,n)scanf("%lld",&a[i]);
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    rep(i,a.size())sum[SEG-1+a[i]]++;
    for(int i=SEG-2;i>=0;i--)sum[i]=sum[i*2+1]+sum[i*2+2];

    int X=0;
    while(m--){
        int x;scanf("%lld",&x);
        X^=x;

        int k=0;
        int ans=0;
        for(int i=18;i>=0;i--){
            int l=sum[k*2+1+(X>>i&1)]==(1<<i);
            ans|=l<<i;
            k=k*2+1+(l^(X>>i&1));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
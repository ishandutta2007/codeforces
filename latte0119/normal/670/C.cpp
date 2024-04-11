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


int b[200000],c[200000];

signed main(){
    int n;
    scanf("%lld",&n);
    map<int,int>cnt;
    rep(i,n){
        int a;
        scanf("%lld",&a);
        cnt[a]++;
    }

    int ma=-1;
    pint v(-1,-1);
    int m;
    scanf("%lld",&m);
    rep(i,m)scanf("%lld",&b[i]);
    rep(i,m)scanf("%lld",&c[i]);

    rep(i,m){
        pint u(cnt[b[i]],cnt[c[i]]);
        if(v<u){
            v=u;
            ma=i;
        }
    }

    printf("%lld\n",ma+1);
    return 0;
}
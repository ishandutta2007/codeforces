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



signed main(){
    int N;
    scanf("%lld",&N);

    vector<vint>v;
    rep(i,N){
        int a;scanf("%lld",&a);
        int lb=-1,ub=v.size();
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(v[mid].back()<a)ub=mid;
            else lb=mid;
        }
        if(ub==v.size())v.pb(vint(1,a));
        else v[ub].pb(a);
    }

    rep(i,v.size()){
        rep(j,v[i].size()){
            if(j)printf(" ");
            printf("%lld",v[i][j]);
        }
        puts("");
    }
    return 0;
}
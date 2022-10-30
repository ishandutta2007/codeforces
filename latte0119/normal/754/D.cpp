#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,K;
int L[333333],R[333333];
vector<int>xs;

vector<int>latte[666666];

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld%lld",&L[i],&R[i]),L[i]--;
    rep(i,N){
        xs.pb(L[i]);xs.pb(R[i]);
    }
    sort(all(xs));xs.erase(unique(all(xs)),xs.end());
    rep(i,N){
        L[i]=lower_bound(all(xs),L[i])-xs.begin();
        R[i]=lower_bound(all(xs),R[i])-xs.begin();
        latte[L[i]].pb(R[i]);
    }

    multiset<int>rs;
    int ma=-1,arcma=-1;
    for(int i=0;i<xs.size();i++){
        for(auto r:latte[i])rs.insert(r);
        while(rs.size()&&*rs.begin()<=i)rs.erase(rs.begin());
        while(rs.size()>K)rs.erase(rs.begin());
        if(rs.size()!=K)continue;
        int tmp=*rs.begin();
        assert(tmp>i);
        if(xs[tmp]-xs[i]>ma){
            ma=xs[tmp]-xs[i];
            arcma=i;
        }
    }

    if(ma==-1){
        puts("0");
        rep(i,K)printf("%lld ",i+1);puts("");return 0;
    }
    printf("%lld\n",ma);
    int cnt=0;
    rep(i,N){
        if(!(xs[L[i]]<=xs[arcma]&&xs[arcma]+ma<=xs[R[i]]))continue;
        printf("%lld ",i+1);
        cnt++;
        if(cnt==K)break;
    }
    puts("");
    return 0;
}
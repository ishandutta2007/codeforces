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

int N;
int A[111111][3];

signed main(){
    cin>>N;
    rep(i,N)rep(j,3)cin>>A[i][j];
    map<pint,vpint>M;
    rep(i,N){
        rep(j,3)rep(k,3){
            if(j==k||A[i][j]>A[i][k])continue;
            int l;
            rep(x,3)if(x!=j&&x!=k)l=x;
            M[{A[i][j],A[i][k]}].pb({A[i][l],i});
        }
    }

    pint ans(-1,-1);
    int val=0;
    each(it,M){
        it->se.pb({0,-1});
        sort(all(it->se));
        it->se.erase(unique(all(it->se)),it->se.end());
        reverse(all(it->se));
        int a=it->fi.fi;
        int b=it->fi.se;
        int c=it->se[0].fi+it->se[1].fi;
        int tmp=min(min(a,b),c);
        if(tmp>val){
            val=tmp;
            ans={it->se[0].se,it->se[1].se};
        }
    }

    if(ans.se==-1){
        cout<<1<<endl<<ans.fi+1<<endl;
    }
    else{
        cout<<2<<endl<<ans.fi+1<<" "<<ans.se+1<<endl;
    }
    return 0;
}
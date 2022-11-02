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


const int INF=1001001001001001001ll;

int N;
int X[333333];
char C[333333];


vint rs[333333],bs[333333];

int calc(vint &v,int l,int r){
    if(v.size()==0)return 0;
    sort(all(v));
    if(l==-INF&&r==INF){
        return v.back()-v.front();
    }

    int ret=min(v.back()-l,r-v.front());
    for(int i=0;i+1<v.size();i++){
        chmin(ret,v[i]-l+r-v[i+1]);
    }
    return ret;
}

signed main(){
    cin>>N;
    rep(i,N)cin>>X[i]>>C[i];

    vint xs={-INF};
    rep(i,N){
        if(C[i]=='G'){
            xs.pb(X[i]);
        }
    }
    xs.pb(INF);sort(all(xs));

    rep(i,N){
        int k=lower_bound(all(xs),X[i])-xs.begin()-1;
        if(C[i]=='R'){
            rs[k].pb(X[i]);
        }
        else if(C[i]=='B'){
            bs[k].pb(X[i]);
        }
    }

    int ans=0;
    for(int i=0;i+1<xs.size();i++){
        int tmp=0;
        tmp+=calc(rs[i],xs[i],xs[i+1]);
        tmp+=calc(bs[i],xs[i],xs[i+1]);
        if(i==0||i+2==xs.size()){
            ans+=tmp;
            continue;
        }
        tmp+=xs[i+1]-xs[i];
        chmin(tmp,(xs[i+1]-xs[i])*2);
        ans+=tmp;
    }

    cout<<ans<<endl;
    return 0;
}
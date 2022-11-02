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
template<typename A,typename B>inline void chmin(A &a,B &b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B &b){if(a<b)a=b;}


int N;
int A[100000];
vpint G[100000];

int dfs(int v,int d,int m){
    int ret=0;
    chmin(m,d);
    if(d-m>A[v]){
        ret++;
        m=-1001001001001001001ll;
    }
    rep(i,G[v].size()){
        int u,c;
        tie(u,c)=G[v][i];
        ret+=dfs(u,d+c,m);
    }
    return ret;
}

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];
    rep(i,N-1){
        int p,c;
        cin>>p>>c;
        p--;
        G[p].pb(pint(i+1,c));
    }

    cout<<dfs(0,0,0)<<endl;
    return 0;
}
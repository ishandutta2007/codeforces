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
    int H,W;
    cin>>H>>W;

    vector<vint>A(H,vint(W));
    rep(i,H)rep(j,W)cin>>A[i][j];


    vector<vint>G(W);
    rep(i,H){
        vpint v;
        rep(j,W)if(A[i][j]!=-1)v.pb({A[i][j],j});
        sort(all(v));
        int cur=0;
        while(cur<v.size()){
            int nex=cur;
            while(nex<v.size()&&v[cur].fi==v[nex].fi)nex++;

            G.pb(vint());
            for(int j=cur;j<nex;j++){
                if(cur!=0)G[v[j].se].pb(G.size()-2);
                G[G.size()-1].pb(v[j].se);
            }
            cur=nex;
        }
    }

    queue<int>que;
    vint deg(G.size());
    rep(i,G.size())for(auto u:G[i])deg[u]++;
    rep(i,G.size())if(deg[i]==0)que.push(i);
    vint ans;

    while(que.size()){
        int v=que.front();
        que.pop();
        if(v<W)ans.pb(v);
        for(auto u:G[v]){
            if(--deg[u]==0)que.push(u);
        }
    }

    if(ans.size()!=W)cout<<-1<<endl;
    else{
        reverse(all(ans));
        rep(i,W)cout<<ans[i]+1<<" ";cout<<endl;
    }
    return 0;
}
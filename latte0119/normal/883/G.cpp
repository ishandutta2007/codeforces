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

int N,M,S;
int T[333333],A[333333],B[333333];

void latte(){
    vector<vint>G(N);
    rep(i,M){
        if(T[i]==2){
            G[A[i]].pb(B[i]);
            G[B[i]].pb(A[i]);
        }
        else G[A[i]].pb(B[i]);
    }

    vint dis(N,-1);
    dis[S]=0;
    queue<int>que;
    que.push(S);
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:G[v]){
            if(dis[u]!=-1)continue;
            dis[u]=dis[v]+1;
            que.push(u);
        }
    }

    int ans=N-count(all(dis),-1);
    string st;
    rep(i,M){
        if(T[i]==1)continue;
        if(dis[A[i]]<dis[B[i]])st+='+';
        else st+='-';
    }
    cout<<ans<<endl;
    cout<<st<<endl;
}

void malta(){
    vector<vint>G(N);
    rep(i,M){
        if(T[i]==2)continue;
        G[A[i]].pb(B[i]);
    }

    vint vis(N);
    vis[S]=1;
    queue<int>que;
    que.push(S);
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:G[v]){
            if(vis[u])continue;
            vis[u]=true;
            que.push(u);
        }
    }

    int ans=accumulate(all(vis),0ll);
    string st;
    rep(i,M){
        if(T[i]==1)continue;
        if(vis[A[i]]==vis[B[i]])st+='+';
        else if(vis[A[i]])st+='-';
        else st+='+';
    }
    cout<<ans<<endl;
    cout<<st<<endl;
}

signed main(){
    cin>>N>>M>>S;
    S--;
    rep(i,M){
        cin>>T[i]>>A[i]>>B[i];
        A[i]--;B[i]--;
    }

    latte();
    malta();
    return 0;
}
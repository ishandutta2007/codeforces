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

int N,M;
vint G[555];

int A[111111],B[111111];

vint det(){
    rep(i,M)G[A[i]].pb(B[i]);
    vint deg(N);
    rep(i,M)deg[B[i]]++;

    queue<int>que;
    rep(i,N)if(deg[i]==0)que.push(i);
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:G[v]){
            if(--deg[u]==0)que.push(u);
        }
    }

    if(count(all(deg),0)==N)return {-1};

    vint ret;
    rep(i,M){
        if(deg[B[i]]==1)ret.pb(i);
    }
    return ret;
}

bool check(int k){
    rep(i,N)G[i].clear();
    rep(i,M)if(i!=k)G[A[i]].pb(B[i]);
    vint deg(N);
    rep(i,M)if(i!=k)deg[B[i]]++;

    queue<int>que;
    rep(i,N)if(deg[i]==0)que.push(i);
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:G[v]){
            if(--deg[u]==0)que.push(u);
        }
    }
    return count(all(deg),0)==N;
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M){
        scanf("%lld%lld",&A[i],&B[i]);
        A[i]--;B[i]--;
    }

    vint lis=det();
    if(lis.size()==0){
        cout<<"NO"<<endl;
        return 0;
    }
    if(lis[0]==-1){
        cout<<"YES"<<endl;
        return 0;
    }

    rep(i,lis.size()){
        if(check(lis[i])){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
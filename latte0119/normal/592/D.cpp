#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<climits>
using namespace std;
typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=123456;

int N,M;
bool need[SIZE];
vint G[SIZE];

int cost1[SIZE],cost2[SIZE],cost3[SIZE],start1[SIZE],start2[SIZE];
int cnt[SIZE],sz[SIZE];

void dfs(int v,int p){
    sz[v]++;
    if(need[v])cnt[v]++;

    int sum=0;
    rep(i,G[v].size()){
        int to=G[v][i];
        if(to==p)continue;
        dfs(to,v);
        sz[v]+=sz[to];
        cnt[v]+=cnt[to];
        if(cnt[to])sum+=cost3[to]+2;
    }

    if(cnt[v]==0)return;
    if(cnt[v]==1&&need[v]){
        start1[v]=v;
        start2[v]=v;
        return;
    }

    cost3[v]=sum;

    int mi=1001001001,from=0;
    rep(i,G[v].size()){
        int to=G[v][i];
        if(to==p)continue;
        if(cnt[to]==0)continue;
        int tmp=sum-cost3[to]-2;
        if(mi>tmp+cost1[to]+1){
            mi=tmp+cost1[to]+1;
            start1[v]=start1[to];
            from=to;
        }
        else if(mi==tmp+cost1[to]+1&&start1[v]>start1[to]){
            start1[v]=start1[to];
            from=to;
        }
    }

    cost1[v]=mi;

    mi=1001001001;
    rep(i,G[v].size()){
        int to=G[v][i];
        if(to==p)continue;
        if(cnt[to]==0)continue;
        int tmp=sum-cost3[to]-2;
        if(mi>tmp+cost2[to]+2){
            mi=tmp+cost2[to]+2;
            start2[v]=start2[to];
        }
        else if(mi==tmp+cost2[to]+2)chmin(start2[v],start2[to]);

        if(to==from)continue;
        tmp=sum-cost3[to]-cost3[from]-4;
        if(mi>tmp+cost1[from]+cost1[to]+2){
            mi=tmp+cost1[from]+cost1[to]+2;
            start2[v]=min(start1[from],start1[to]);
        }
        else if(mi==tmp+cost1[from]+cost1[to]+2)chmin(start2[v],min(start1[from],start1[to]));
    }

    cost2[v]=mi;
}

int main(){
    scanf("%d%d",&N,&M);
    rep(i,N-1){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    rep(i,M){
        int a;scanf("%d",&a);
        a--;
        need[a]=true;
    }

    dfs(0,-1);
    int idx,ans=1001001001;
    rep(i,N){
        if(cnt[i]!=M)continue;
        if(ans>cost1[i]){
            ans=cost1[i];
            idx=min(i,start1[i]);
        }
        else if(ans==cost1[i])chmin(idx,min(i,start1[i]));

        if(ans>cost2[i]){
            ans=cost2[i];
            idx=start2[i];
        }
        else if(ans==cost2[i])chmin(idx,start2[i]);
    }
    /*
    rep(i,N)cout<<cost1[i]<<" ";cout<<endl;
    rep(i,N)cout<<cost2[i]<<" ";cout<<endl;
    rep(i,N)cout<<cost3[i]<<" ";cout<<endl;
    rep(i,N)cout<<start1[i]<<" ";cout<<endl;
    rep(i,N)cout<<start2[i]<<" ";cout<<endl;
    rep(i,N)cout<<cnt[i]<<" ";cout<<endl;
    */
    printf("%d\n%d\n",idx+1,ans);
    return 0;
}
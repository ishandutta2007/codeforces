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

int N;
vint G[222222];

bool centroid[222222];
int subtree_size[222222];

int compute_subtree_size(int v,int p){
  int c=1;
  for(auto u:G[v]){
    if(u==p||centroid[u])continue;
    c+=compute_subtree_size(u,v);
  }
  subtree_size[v]=c;
  return c;
}

pair<int,int>search_centroid(int v,int p,int t){
  pair<int,int>res={INT_MAX,-1};
  int s=1,m=0;
  for(auto u:G[v]){
    if(u==p||centroid[u])continue;
    res=min(res,search_centroid(u,v,t));
    m=max(m,subtree_size[u]);
    s+=subtree_size[u];
  }
  m=max(m,t-s);
  res=min(res,{m,v});
  return res;
}


vector<tuple<int,int,int>>ans;
int g;
int s;
int pre;

void dfs(int v,int p,int d){
    for(auto u:G[v]){
        if(u==p)continue;
        dfs(u,v,d+1);
    }
    if(d>1){
        ans.pb(make_tuple(g,pre,v));
        ans.pb(make_tuple(v,p,s));
        pre=v;
    }
}

signed main(){
    cin>>N;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    compute_subtree_size(0,-1);
    int x=search_centroid(0,-1,N).se;

    compute_subtree_size(x,-1);
    int y=-1;
    for(auto u:G[x]){
        if(subtree_size[u]*2==N){
            y=u;
        }
    }


    for(auto u:G[x]){
        if(u==y)continue;
        g=x;
        pre=u;
        s=u;
        dfs(u,x,0);

        if(pre!=u){
            ans.pb(make_tuple(x,pre,u));
        }
    }

    if(y!=-1){
        for(auto u:G[y]){
            if(u==x)continue;
            g=y;
            pre=u;
            s=u;
            dfs(u,y,0);

            if(pre!=u){
                ans.pb(make_tuple(y,pre,u));
            }
        }
    }

    printf("%lld\n",(int)ans.size());
    rep(i,ans.size())printf("%lld %lld %lld\n",get<0>(ans[i])+1,get<1>(ans[i])+1,get<2>(ans[i])+1);
    return 0;
}
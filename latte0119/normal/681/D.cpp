#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int>G[100000];
int W[100000];
bool isroot[100000];

int dep[100000];
void dfs(int v,int d){
    dep[v]=d;
    for(int i=0;i<G[v].size();i++){
        int u=G[v][i];
        dfs(u,d+1);
    }
}

bool ex[100000];
bool ok=true;

int dfs2(int v){
    int ret=dep[W[v]];
    for(int i=0;i<G[v].size();i++){
        int u=G[v][i];
        ret=min(ret,dfs2(u));
    }
    if(ex[v]&&dep[v]>ret)ok=false;
    return ret;
}

int main(){
    cin>>N>>M;
    fill_n(isroot,N,true);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        isroot[b]=false;
    }
    for(int i=0;i<N;i++)cin>>W[i],W[i]--,ex[W[i]]=true;

    for(int i=0;i<N;i++)if(isroot[i])dfs(i,0);

    for(int i=0;i<N;i++)if(isroot[i])dfs2(i);

    vector<pair<int,int> >vec;
    for(int i=0;i<N;i++)vec.push_back(pair<int,int>(dep[W[i]],W[i]));
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    if(ok){
        printf("%d\n",(int)vec.size());
        for(int i=vec.size()-1;i>=0;i--)printf("%d\n",vec[i].second+1);
    }
    else{
        puts("-1");
    }
    return 0;
}
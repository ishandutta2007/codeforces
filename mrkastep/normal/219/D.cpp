#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

int n;

bool read(){
    if(scanf("%d",&n)!=1) return false;
    return true;
}

vector<vector<int>> g1,g2;
int d[222222];
bool st[222222];

void deep0(int v){
    int i;
    st[v]=false;
    For(i,g1[v].size()){
        if(st[g1[v][i]]) deep0(g1[v][i]);
    }
    For(i,g2[v].size()){
        if(st[g2[v][i]]){
            deep0(g2[v][i]);
            d[0]++;
        }
    }
}

void deep(int v,int type,int prev){
    int i;
    st[v]=false;
    if(v!=0){
        d[v]=d[prev]+1-2*type;
    }
    For(i,g1[v].size()){
        if(st[g1[v][i]]) deep(g1[v][i],0,v);
    }
    For(i,g2[v].size()){
        if(st[g2[v][i]]) deep(g2[v][i],1,v);
    }
}


void solve(){
    int i,a,b,m;
    vector<int> one,ans;
    For(i,n){
        g1.pb(one);
        g2.pb(one);
    }
    For(i,n-1){
        scanf("%d%d",&a,&b);
        g1[a-1].pb(b-1);
        g2[b-1].pb(a-1);
    }
    For(i,n) st[i]=true;
    d[0]=0;
    deep0(0);
    For(i,n) st[i]=true;
    deep(0,0,0);
    m=1e+9;
    For(i,n){
        if(d[i]<m){
            ans.clear();
            m=d[i];
        }
        if(d[i]==m)ans.pb(i);
    }
    printf("%d\n",m);
    For(i,ans.size())printf("%d ",ans[i]+1);

}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(read()){
        solve();
        printf("\n\n");
    }
    return 0;
}
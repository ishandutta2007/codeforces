#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

set<int> q[512]; // elementos de comp
int n,w[512],a[512]; // w componente de pos
int g[512][512];
bool v[512];

int dfs(int k,int c){
    w[k]=c;
    for(int i=0;i<n;++i){
        if(g[k][i]&&w[i]<0){
            dfs(i,c);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            char c;
            cin>>c;
            g[i][j]=c=='1';
        }
    }
    memset(w,-1,sizeof(w));
    int c=0;
    for(int i=0;i<n;++i){
        if(w[i]==-1){
            dfs(i,c++);
        }
    }
    for(int i=0;i<n;++i){
        q[w[i]].insert(a[i]);
    }
    for(int i=0;i<n;++i){
        printf("%d ", *(q[w[i]].begin()));
        q[w[i]].erase(q[w[i]].begin());
    }
    puts("");
}
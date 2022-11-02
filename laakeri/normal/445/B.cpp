#include <iostream>
#include <vector>

using namespace std;

int used[100];

vector<int> g[100];

long long v=1;

int f=0;

void dfs (int x){
    if (used[x]){
        return;
    }
    used[x]=1;
    f++;
    for (int nx:g[x]){
        if (used[nx]){
            v=v*(long long)2;
            break;
        }
    }
    for (int nx:g[x]){
        dfs(nx);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        dfs(i);
    }
    cout <<v<<endl;
}
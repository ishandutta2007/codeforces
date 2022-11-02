#include <iostream>
#include <vector>

using namespace std;

vector<int> g[300];//*2+1 negaatio

int cc[300];
int v[300];

void dfs(int x, int c){
    if (cc[x]) return;
    cc[x]=c;
    for (int nx:g[x]){
        dfs(nx, c);
    }
}

void dfs2(int x){
    if (v[x]) return;
    v[x]=1;
    if (x%2==0) v[x+1]=2;
    if (x%2==1) v[x-1]=2;
    for (int nx:g[x]){
        dfs2(nx);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if (c==1){
            g[a*2].push_back(b*2);
            g[a*2+1].push_back(b*2+1);
            g[b*2].push_back(a*2);
            g[b*2+1].push_back(a*2+1);
        }
        else{
            g[a*2].push_back(b*2+1);
            g[a*2+1].push_back(b*2);
            g[b*2].push_back(a*2+1);
            g[b*2+1].push_back(a*2);
        }
    }
    for (int i=2;i<n*2+2;i++){
        dfs(i, i);
    }
    for (int i=1;i<=n;i++){
        if (cc[i*2]==cc[i*2+1]){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    for (int i=2;i<n*2+2;i++){
        dfs2(i);
    }
    vector<int> vv;
    for (int i=1;i<=n;i++){
        if (v[i*2]==1){
            vv.push_back(i);
        }
    }
    cout<<vv.size()<<endl;
    for (int x:vv){
        cout<<x<<" ";
    }
}
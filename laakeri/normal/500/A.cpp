#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100001];

int used[100001];

void dfs(int x){
    if (used[x]) return;
    used[x]=1;
    for (int nx:g[x]){
        dfs(nx);
    }
}

int main(){
    int n,t;
    cin>>n>>t;
    for (int i=0;i<n-1;i++){
        int a;
        cin>>a;
        g[i+1].push_back(i+1+a);
    }
    dfs(1);
    if (used[t]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
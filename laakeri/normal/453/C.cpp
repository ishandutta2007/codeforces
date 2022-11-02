#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100001];

int used[100001];

int ne[100001];

vector<int> v;

int ap=0;

int dfs (int x){
    if (used[x]) return 1;
    used[x]=1;
    v.push_back(x);
    for (int nx:g[x]){
        if (dfs(nx)==0){
            v.push_back(x);
            used[x]++;
            if (used[nx]%2!=ne[nx]){
                v.push_back(nx);
                v.push_back(x);
                used[nx]++;
                used[x]++;
            }
        }
    }
    return 0;
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
    int f=0;
    for (int i=0;i<n;i++) {
        cin>>ne[i+1];
        if (ne[i+1]) f=i+1;
    }
    if (f) {
        ap=f;
        dfs(f);
        f=0;
        for (int i=1;i<=n;i++){
            if (i!=ap){
                if (used[i]%2!=ne[i]){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
        if (used[ap]%2!=ne[ap]){
            cout<<v.size()-1<<endl;
            for (int i=0;i<v.size()-1;i++){
                cout<<v[i]<<" ";
            }
        }
        else{
            cout<<v.size()<<endl;
            for (int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
        }
    }
    else{
        cout<<0<<endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[301];

int git=1;

vector<int> cc[301];
vector<int> cch[301];

int used[301];

int a[301];

void dfs(int x, int c){
    if (used[x]) return;
    used[x]=1;
    cc[c].push_back(x);
    cch[c].push_back(a[x]);
    for (int nx:g[x]){
        dfs(nx, c);
    }
}

int v[301];

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i+1];
    }
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        for (int ii=0;ii<n;ii++){
            if (s[ii]=='1'){
                g[i].push_back(ii+1);
                g[ii+1].push_back(i);
            }
        }
    }
    int ii=0;
    for (int i=1;i<=n;i++){
        if (!used[i]){
            dfs(i, ii);
            ii++;
        }
    }
    for (int i=0;i<ii;i++){
        sort(cch[i].begin(), cch[i].end());
        sort(cc[i].begin(), cc[i].end());
        for (int ii=0;ii<cc[i].size();ii++){
            v[cc[i][ii]]=cch[i][ii];
        }
    }
    for (int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
}
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int a[202020];
int y[202020];
vector<int> g[202020];

int aps[202020];

void dfs0(int x, int p){
    if (g[x].size()==1&&x>1) aps[x]=1;
    for (int nx:g[x]){
        if (nx!=p){
            dfs0(nx, x);
            aps[x]+=aps[nx];
        }
    }
}

void dfs1(int x, int p, int d){//tapaus maksimointi
    for (int nx:g[x]){
        if (nx!=p){
            dfs1(nx, x, d+1);
            if (d%2==0){
                a[x]=max(a[x], aps[x]-aps[nx]+a[nx]);
            }
            else{
                a[x]+=a[nx];
            }
        }
    }
}

void dfs2(int x, int p, int d){//tapaus maksimointi
    for (int nx:g[x]){
        if (nx!=p){
            dfs2(nx, x, d+1);
            if (d%2==1){
                y[x]=max(y[x], aps[x]-aps[nx]+y[nx]);
            }
            else{
                y[x]+=y[nx];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if (n==1){
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    for (int i=0;i<n-1;i++){
        int aa,b;
        cin>>aa>>b;
        g[aa].push_back(b);
        g[b].push_back(aa);
    }
    dfs0(1, 0);
    dfs1(1, 0, 0);
    dfs2(1, 0, 0);
    cout<<a[1]+1<<" "<<aps[1]-y[1]<<endl;
}
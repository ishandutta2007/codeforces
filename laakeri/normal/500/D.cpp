#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double ld;

vector<int> g[100001];

int a[100001];
int b[100001];
ld l[100001];

int aps[100001];
int p[100001];

ld ncr[4][100001];

void dfs(int x, int tp){
    p[x]=tp;
    aps[x]=1;
    for (int nx:g[x]){
        if (nx!=tp){
            dfs(nx, x);
            aps[x]+=aps[nx];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        cin>>a[i]>>b[i]>>l[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    dfs(1, 0);
    ncr[0][1]=1;
    ncr[1][1]=1;
    for (int i=2;i<=100000;i++){
        ncr[0][i]=1;
        for (int ii=1;ii<=3;ii++){
            ncr[ii][i]=ncr[ii-1][i-1]+ncr[ii][i-1];
        }
    }
    ld ap=ncr[3][n];
    ld ev=0;
    for (int i=1;i<n;i++){
        int x=a[i];
        if (a[i]==p[b[i]]){
            x=b[i];
        }
        x=aps[x];
        ev+=(ap-ncr[3][x]-ncr[3][n-x])*2*l[i];
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int t;
        ld nl;
        cin>>t>>nl;
        int x=a[t];
        if (a[t]==p[b[t]]){
            x=b[t];
        }
        x=aps[x];
        ld d=l[t]-nl;
        ev-=(ap-ncr[3][x]-ncr[3][n-x])*(long double)2*d;
        l[t]-=d;
        cout<<setprecision(15)<<ev/ap<<'\n';
    }
}
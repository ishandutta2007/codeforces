#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

int c[100001];
vector<int> g[100001];

int h[100011];

int hc[100011];

vector<int> q[100001];
int qk[100001];
int v[100001];

vector<pair<int,int>> nt;

int as[100001];

void dfsd(int x, int p){
    as[x]=1;
    for (int nx:g[x]){
        if (nx!=p) {
            dfsd(nx, x);
            as[x]+=as[nx];
        }
    }
}

int it=0;

void dfs(int x, int p, int tr){
    int mmdx=0;
    it++;
    if (tr){
        int mmd=0;
        for (int nx:g[x]){
            if (nx!=p){
                if (as[nx]>mmd){
                    mmd=as[nx];
                    mmdx=nx;
                }
            }
        }
        if (mmd){
            dfs(mmdx, x, 1);
        }
    }
    for (int nx:g[x]){
        if (nx!=p&&nx!=mmdx){
            dfs(nx, x, 0);
            if (tr==1){
                nt.push_back(make_pair(nx, x));
            }
        }
    }
    hc[c[x]]++;
    h[hc[c[x]]]++;
    if (tr){
        for (int qq:q[x]){
            v[qq]+=h[qk[qq]];
        }
    }
}

int mhc=0;

void dfsc(int x, int p){
    for (int nx:g[x]){
        if (nx!=p){
            dfsc(nx, x);
        }
    }
    mhc=max(hc[c[x]], mhc);
    hc[c[x]]=0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>c[i+1];
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=0;i<m;i++){
        int a;
        cin>>a>>qk[i+1];
        q[a].push_back(i+1);
    }
    dfsd(1, 0);
    nt.push_back(make_pair(1, 0));
    while (nt.size()>0){
        int a=nt.back().first;
        int b=nt.back().second;
        nt.pop_back();
        dfs(a, b, 1);
        mhc=0;
        dfsc(a, b);
        for (int i=0;i<=mhc;i++){
            h[i]=0;
        }
    }
    for (int i=1;i<=m;i++){
        cout<<v[i]<<'\n';
    }
}
#include <iostream>
#include <vector>

using namespace std;

int apd[100001];

int hd[100001];

vector<int> g[100001];

int n,m,d;

int v=0;

void dfs2(int x, int p, int pd){
    if (pd>d) return;
    int ok=1;
    int md=-1;
    int mdx=-1;
    int smd=-1;
    if (hd[x]){
        pd=max(pd, 0);
    }
    for (int nx:g[x]){
        if (nx!=p){
            if (apd[nx]>-1&&apd[nx]+1>d){
                ok=0;
            }
            if (apd[nx]>-1&&apd[nx]+1>md){
                smd=md;
                md=apd[nx]+1;
                mdx=nx;
            }
            else if(apd[nx]>-1&&apd[nx]+1>smd){
                smd=apd[nx]+1;
            }
        }
    }
    if (ok) v++;
    for (int nx:g[x]){
        if (nx!=p){
            if (nx!=mdx){
                if (pd>-1||md>-1){
                    dfs2(nx, x, max(pd, md)+1);
                }
                else{
                    dfs2(nx, x, -1);
                }
            }
            else{
                if (pd>-1||smd>-1){
                    dfs2(nx, x, max(pd, smd)+1);
                }
                else{
                    dfs2(nx, x, -1);
                }
            }
        }
    }
}

void dfs1(int x, int p){
    apd[x]=-1;
    for (int nx:g[x]){
        if (nx!=p){
            dfs1(nx, x);
            if (apd[nx]>=0){
                apd[x]=max(apd[x], apd[nx]+1);
            }
        }
    }
    if (hd[x]){
        apd[x]=max(apd[x], 0);
    }
}

int main(){
    cin>>n>>m>>d;
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        hd[a]=1;
    }
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0, -1);
    cout<<v<<endl;
}
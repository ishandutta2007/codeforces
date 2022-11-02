#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define F first
#define S second

using namespace std;

vector<int> g[100001];
vector<int> gr[100001];
int used1[100001];
vector<int> s1;
void dfs1(int x){
    if (used1[x]) return;
    used1[x]=1;
    for (int nx:g[x]){
        dfs1(nx);
    }
    s1.push_back(x);
}
int scc[100001];
int sccs[100001];
void dfs2(int x, int c){
    if (scc[x]) return;
    scc[x]=c;
    sccs[c]++;
    for (int nx:gr[x]){
        dfs2(nx, c);
    }
}

int nok[100001];

void dfs3(int x){
    if (nok[x]) return;
    nok[x]=1;
    for (int nx:g[x]){
        dfs3(nx);
    }
    for (int nx:gr[x]){
        dfs3(nx);
    }
}

int cc2[100001];
vector<int> cc2h[100001];

int ec[100001];

set<pair<int, int> > el[100001];

void dfs4(int x, int c){
    if (cc2[x]) return;
    cc2[x]=c;
    cc2h[c].push_back(x);
    for (int nx:g[x]){
        dfs4(nx, c);
        ec[nx]++;
        el[c].insert({x, nx});
    }
    for (int nx:gr[x]){
        dfs4(nx, c);
    }
}

int mad[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        dfs1(i);
    }
    int ss=1;
    for (int i=n-1;i>=0;i--){
        if (scc[s1[i]]==0){
            dfs2(s1[i], ss++);
            if (sccs[ss-1]>1){
                dfs3(s1[i]);
            }
        }
    }
    int v=0;
    vector<int> txx;
    for (int i=1;i<=n;i++){
        if (nok[i]) v++;
        else{
            txx.push_back(i);
        }
    }
    int ii=1;
    for (int x:txx){
        if (!cc2[x]) dfs4(x, ii++);
    }
    for (int i=1;i<ii;i++){
        v+=cc2h[i].size()-1;
        /*
        int tv=0;
        queue<int> topo;
        for (int x:cc2h[i]){
            if (ec[x]==0) {
                topo.push(x);
                mad[x]=1;
            }
        }
        while (!topo.empty()){
            int x=topo.front();
            topo.pop();
            for (int nx:g[x]){
                ec[nx]--;
                mad[nx]=max(mad[nx], mad[x]+1);
                if (ec[nx]==0){
                    topo.push(nx);
                }
            }
        }
        for (auto e:el[i]){
            if (mad[e.S]-mad[e.F]==1){
                tv++;
            }
        }
        cout<<tv<<" "<<(int)cc2h[i].size()<<endl;
        v+=min(tv, (int)cc2h[i].size());
        */
    }
    cout<<v<<endl;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e9

const int MX=4e5, MXB=MX*3*3;
int n, p, M, m, N;
int x[MX], y[MX], l[MX], r[MX], u[MX], v[MX];
vi adjList[MXB];
vi adjListR[MXB];
bitset<MXB> vis;
stack<int> stck;
int group[MXB], groups=0;

int get(int i, bool j) {
    return i*2 + j;
}
int moreThen(int i) {
    return p*2 + i;
}
int lessThen(int i) {
    return p*2 + M + i;

}
void addCompare() {
    REP(i,0,M-1)
        adjList[moreThen(i)].push_back(moreThen(i+1));
    REP(i,1,M)
        adjList[lessThen(i)].push_back(lessThen(i-1));
    REP(i,0,p) {
        if(l[i] != 0) {
            adjList[moreThen(l[i]-1)].push_back(get(i,0));
        }
        if(r[i] != M-1) {
            adjList[lessThen(r[i]+1)].push_back(get(i,0));
        }
        adjList[get(i,1)].push_back(moreThen(r[i]));
        adjList[get(i,1)].push_back(lessThen(l[i]));
    }
}
void reverseAdj() {
    REP(i,0,N)
        REP(j,0,adjList[i].size())
            adjListR[adjList[i][j]].push_back(i);
    REP(i,0,N) adjList[i]=adjListR[i];
}
void dfs1(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    REP(i,0,adjList[u].size())
        dfs1(adjList[u][i]);
    stck.push(u);
}
void dfs2(int u, int r) {
    if(vis[u]) return;
    group[u] = r;
    vis[u] = 1;
    REP(i,0,adjList[u].size())
        dfs2(adjList[u][i], r);
}

int main() {
    cin>>n>>p>>M>>m;
    N = (p+M)*2;
    REP(i,0,n) cin>>x[i]>>y[i],x[i]--,y[i]--;
    REP(i,0,p) cin>>l[i]>>r[i],l[i]--,r[i]--;
    REP(i,0,m) cin>>u[i]>>v[i],u[i]--,v[i]--;
    REP(i,0,n) {
        adjList[get(x[i],0)].push_back(get(y[i],1));
        adjList[get(y[i],0)].push_back(get(x[i],1));
    }
    REP(i,0,m) {
        adjList[get(u[i],1)].push_back(get(v[i],0));
        adjList[get(v[i],1)].push_back(get(u[i],0));
    }
    addCompare();
    vis.reset();
    REP(i,0,N) dfs1(i);
    reverseAdj();
    vis.reset();
    while(!stck.empty()) {
        int i=stck.top(); stck.pop();
        dfs2(i, groups++);
    }
    bool pos=1;
    vi ans;
    REP(i,0,p) {
        if(group[get(i,0)]==group[get(i,1)])
            pos=0;
        if(group[get(i,0)]<group[get(i,1)])
            ans.push_back(i);
    }
    if(!pos) {
        cout<<-1<<endl;
    } else {
        int f=INF;
        REP(i,0,ans.size())
            f = min(f,r[ans[i]]+1);
        cout<<ans.size()<<" "<<f<<endl;
        REP(i,0,ans.size()) {
            if(i!=0) cout<<" ";
            cout<<ans[i]+1;
        }
        cout<<endl;
    }
}
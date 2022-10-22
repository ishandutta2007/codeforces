#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 2000;

int n, b, e;
vi adjList[MX];
int treeSize[MX];
int a[MX];
int ai;

void addA(int root, int parent, int depth) {
    cout<<root+1<<" "<<parent+1<<" "<<a[ai]-depth<<endl;
    depth = a[ai++];
    REP(i,0,adjList[root].size()) {
        int v = adjList[root][i];
        if(v == parent) continue;
        addA(v, root, depth);
    }
}
int dfs(int root, int parent=-1) {
    treeSize[root] = 1;
    REP(i,0,adjList[root].size()) {
        int v = adjList[root][i];
        if(v == parent) continue;
        treeSize[root] += dfs(v, root);
    }
    return treeSize[root];
}
int getCentroid(int root, int parent=-1) {
    bool cent=1;
    int heavy=-1;
    REP(i,0,adjList[root].size()) {
        int v=adjList[root][i];
        if(v == parent) continue;
        if(treeSize[v] > n/2) cent=0;
        if(heavy == -1 || treeSize[v] > treeSize[heavy])
            heavy = v;
    }

    if(cent) return root;
    return getCentroid(heavy, root);
}
int getCentroid() {
    dfs(0);
    return getCentroid(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n-1)
        cin>>b>>e, b--, e--, adjList[b].push_back(e), adjList[e].push_back(b);

    if(n == 1) return 0;
    if(n == 2) {
        cout<<"1 2 1"<<endl;
        return 0;
    }

    int cent = getCentroid();
    dfs(cent);

    priority_queue<pair<int, vi>, vector<pair<int, vi>>, greater<pair<int, vi>>> groups;
    REP(i,0,adjList[cent].size()) {
        int v = adjList[cent][i];
        groups.push({treeSize[v], {v}});
    }
    while(groups.size() >= 3) {
        auto p1 = groups.top(); groups.pop();
        auto p2 = groups.top(); groups.pop();
        p2.first += p1.first;
        p2.second.insert(p2.second.end(), p1.second.begin(), p1.second.end());
        groups.push(p2);
    }

    auto groupa = groups.top(); groups.pop();
    auto groupb = groups.top(); groups.pop();

    //group a
    REP(i,0,groupa.first) a[i] = i+1;
    ai = 0;
    REP(i,0,groupa.second.size()) {
        int v = groupa.second[i];
        addA(v, cent, 0);
    }

    //group b
    REP(i,0,groupb.first) a[i] = (i+1)*(groupa.first+1);
    ai = 0;
    REP(i,0,groupb.second.size()) {
        int v = groupb.second[i];
        addA(v, cent, 0);
    }
}
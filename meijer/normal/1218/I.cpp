#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=2000, MXN=MX*5;
int N, n;
string S[MX], T[MX], M;
bitset<MX> s[MX], t[MX], m;
vi adjList[MXN], adjListR[MXN];
bitset<MXN> visited;
int comp[MXN], sccs=0;
stack<int> stck;

int getRN(int i, int b) {
    return i*2 + b;
}
int getCN(int i, int b) {
    return N*2 + i*2 + b;
}

void reverseEdges() {
    RE(i,n)
        for(int v:adjList[i])
            adjListR[v].pb(i);
    RE(i,n) adjList[i]=adjListR[i];
}
void dfs1(int u) {
    if(visited[u]) return;
    visited[u] = 1;
    for(int v:adjList[u])
        dfs1(v);
    stck.push(u);
}
void dfs2(int u, int r) {
    if(visited[u]) return;
    visited[u] = 1;
    comp[u] = r;
    for(int v:adjList[u])
        dfs2(v, r);
}
void findScc() {
    visited.reset();
    RE(i,n) dfs1(i);
    visited.reset();
    reverseEdges();
    while(!stck.empty()) {
        int u=stck.top(); stck.pop();
        if(!visited[u]) dfs2(u, sccs++);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N; n=N*4;
    RE(i,N) cin>>S[i];
    RE(i,N) cin>>T[i];
    cin>>M;
    RE(i,N) RE(j,N) s[i][j] = S[i][j]=='1', t[i][j] = T[i][j]=='1';
    RE(i,N) m[i] = M[i]=='1';
    RE(r,N) {
        RE(c,N) {
            if(s[r][c] == t[r][c]) {
                //stay the same
                if(m[r] && m[c]) {
                    adjList[getRN(r,0)].pb(getCN(c,0));
                    adjList[getCN(c,0)].pb(getRN(r,0));
                    adjList[getRN(r,1)].pb(getCN(c,1));
                    adjList[getCN(c,1)].pb(getRN(r,1));
                } else
                if(m[r]) {
                    adjList[getCN(c,1)].pb(getCN(c,0));
                } else
                if(m[c]) {
                    adjList[getRN(r,1)].pb(getRN(r,0));
                }
            } else {
                //change
                if(m[r] && m[c]) {
                    adjList[getRN(r,0)].pb(getCN(c,1));
                    adjList[getCN(c,0)].pb(getRN(r,1));
                    adjList[getRN(r,1)].pb(getCN(c,0));
                    adjList[getCN(c,1)].pb(getRN(r,0));
                } else
                if(m[r]) {
                    adjList[getCN(c,0)].pb(getCN(c,1));
                } else
                if(m[c]) {
                    adjList[getRN(r,0)].pb(getRN(r,1));
                } else {
                    //not possible
                    adjList[getRN(r,0)].pb(getRN(r,1));
                    adjList[getRN(r,1)].pb(getRN(r,0));
                    adjList[getCN(c,0)].pb(getCN(c,1));
                    adjList[getCN(c,1)].pb(getCN(c,0));
                }
            }
        }
    }

    findScc();
    bool possible = 1;
    RE(i,N) {
        if(comp[getRN(i,0)] == comp[getRN(i,1)]) possible=0;
        if(comp[getCN(i,0)] == comp[getCN(i,1)]) possible=0;
    }
    if(possible) {
        vi rows;
        vi cols;
        RE(i,N) {
            if(comp[getRN(i,0)] < comp[getRN(i,1)]) rows.pb(i);
            if(comp[getCN(i,0)] < comp[getCN(i,1)]) cols.pb(i);
        }
        cout<<rows.size()+cols.size()<<endl;
        for(int v:rows) cout<<"row "<<v<<endl;
        for(int v:cols) cout<<"col "<<v<<endl;
    } else {
        cout<<-1<<endl;
    }
}
// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

struct edge { int k,c; edge(int k,int c):k(k),c(c){} };

int N;
int P[5024];
vector< vector<edge> > G;
vector<int> bfsorder;
vector<int> parent;
vector<int> answer;

int main() {
    cin >> N;
    REP(n,N) cin >> P[n];
    G.resize(N);
    REP(n,N-1) { int x,y,c; cin>>x>>y>>c; --x; --y; G[x].push_back(edge(y,c)); G[y].push_back(edge(x,c)); }
    vector<bool> seen(N,false);
    seen[0]=true;
    queue<int> Q;
    Q.push(0);
    bfsorder.push_back(0);
    parent.resize(N,-1);
    while (!Q.empty()) {
        int x=Q.front(); Q.pop();
        REP(i,SIZE(G[x])) {
            if (seen[G[x][i].k]) continue;
            seen[G[x][i].k]=true;
            Q.push(G[x][i].k);
            bfsorder.push_back(G[x][i].k);
            parent[ G[x][i].k ] = x;
        }
    }
    
    vector<int> parentcap(N,0);
    REP(n,N) REP(i,SIZE(G[n])) if (G[n][i].k == parent[n]) parentcap[n]=G[n][i].c;
    
    answer.resize(N,0);
    vector< priority_queue<PII> > W(N);
    REP(n,N) W[n].push( PII(-P[n],n) );
    int day = 0;
    while (true) {
        ++day;
        bool change = false;
        REP(n,N) {
            int x = bfsorder[n];
            if (x==0) continue;
            int moved = 0;
            while (!W[x].empty() && moved < parentcap[x]) {
                ++moved;
                int kto = W[x].top().second;
                W[x].pop();
                W[parent[x]].push(PII(-P[kto],kto));
                answer[kto] = day;
                change = true;
            }
        }
        if (!change) break;
    }
    REP(n,N) cout << answer[n] << (n==N-1?"\n":" ");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
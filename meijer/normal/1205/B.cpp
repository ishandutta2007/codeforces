#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a!=int(c); a++)

const int MX = 63;

ll N;
ll M[200000];
ll START[200];
ll cnt[200];
vi adjList[200];
ll d[200];
int sz=0;

int dfs(int e, int b) {
    REP(i,0,sz) d[i]=INF;
    d[b] = 0;
    queue<int> q; q.push(b);

    while(!q.empty()) {
        int v=q.front(); q.pop();
        REP(i,0,adjList[v].size()) {
            int u = adjList[v][i];
            if(v==b && u==e) continue;
            if(d[u] == INF)
                d[u] = d[v]+1, q.push(u);
        }
    }

    return d[e];
}

int main() {
    cin>>N;
    REP(i,0,N) cin>>M[i];

    REP(i,0,MX) cnt[i] = 0;
    REP(i,0,N) {
        REP(j,0,MX) {
            if(M[i] & ((ll)1<<j)) cnt[j]++;
            if(cnt[j] == 3) {
                cout<<"3"<<endl;
                return 0;
            }
        }
    }

    REP(i,0,MX) START[i] = -1;
    REP(i,0,N) {
        bool visited = 0;
        REP(j,0,MX) {
            if(M[i] & ((ll)1<<j)) {
                if(cnt[j] != 2) continue;
                visited = 1;
                if(START[j] == -1) {
                    START[j] = sz;
                } else {
                    adjList[sz      ].push_back(START[j]);
                    adjList[START[j]].push_back(sz      );
                }
            }
        }
        if(visited) sz++;
    }

    int mn = INF;
    REP(i,0,sz) {
        REP(j,0,adjList[i].size()) {
            mn = min(mn, dfs(i, adjList[i][j])+1);
        }
    }
    cout<<(mn==INF?-1:mn)<<endl;
}
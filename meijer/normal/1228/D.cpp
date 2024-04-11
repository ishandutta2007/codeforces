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

const int MX=1e5;
set<int> adj[MX];
int n, m, a, b;
int group[MX], groups=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    REP(i,0,m) cin>>a>>b, a--, b--, adj[a].insert(b), adj[b].insert(a);
    RE(i,n) group[i]=-1;
    RE(i,n) {
        if(group[i] != -1) continue;
        group[i] = ++groups;
        RE(j,n) {
            if(adj[i].count(j) == 0) {
                group[j] = groups;
                if(adj[j] != adj[i]) {
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
    }
    if(groups != 3) {
        cout<<-1<<endl;
    } else {
        cout<<group[0];
        REP(i,1,n) cout<<" "<<group[i];
        cout<<endl;
    }
}
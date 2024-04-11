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

const int MX=7;
int n, m, a, b;
vi adjList[MX];
vi perm;
bitset<MX> used[MX];

int getCount() {
    int tot = 0;
    RE(i,MX) used[i].reset();
    RE(u,n) {
        for(int v:adjList[u]) {
            int a=perm[u], b=perm[v];
            if(!used[a][b])
                used[a][b]=used[b][a]=1, tot++;
        }
    }
    return tot;
}
int getAns(int i=0) {
    if(i == 7) return getCount();
    int ans=0;
    RE(j,6) {
        perm[i] = j;
        ans=max(ans,getAns(i+1));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(i,m) cin>>a>>b, a--, b--, adjList[a].pb(b), adjList[b].pb(a);
    if(n != 7) {
        cout<<m<<endl;
    } else {
        perm.resize(7);
        cout<<getAns()<<endl;
    }
}
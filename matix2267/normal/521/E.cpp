#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef deque<int> di;

const int inft = 1000000009;
const int MAXN = 1000006;

vector<vi> V, C;
char vis[MAXN];
pii ANS = pii(-1,-1);

vi dfs(int u, int par, int depth) {
    //printf("%*sdfs %d %d\n", depth, "", u+1, par+1);
    if(vis[u] == 2) { // u found cycle to par or was pruned
        return vi();
    }
    if(vis[u] == 1) { // cycle
        C.pb(vi(1,u));
        return vi(1, C.size()-1);
    }
    vis[u] = 1;
    vi ourc;
    tr(itz, V[u]) {
        if(*itz == par) continue;
        assert(ourc.size() <= 1);
        vi hcyc = dfs(*itz, u, depth+1);
        tr(it, hcyc) {
            int x = *it;
            if(C[x][0]==u) { // cycle end
                C[x].pb(u);
            } else { // cycle mid
                ourc.pb(x);
                C[x].pb(u);
            }
        }
        while(ourc.size() > 2) ourc.pop_back();
        if(ourc.size() >= 2) ANS = pii(ourc[0], ourc[1]);
        if(ANS != pii(-1,-1)) break;
    }
    vis[u] = 2;
    return ourc;
}

void rotate(di &cyc, const map<pii,int> &M) {
    while(M.find(pii(cyc[0], cyc[1]))->y == 1) {
        cyc.pb(cyc[0]);
        cyc.pop_front();
    }
}

template <typename T>
void wypisz(T v) {
    cout << v.size() << " ";
    tr(it, v) cout << *it + 1 << " ";
    cout << endl;
}

void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    V.resize(n);
    fru(i,m) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        V[a].pb(b);
        V[b].pb(a);
    }
    fru(i,n) if(vis[i]==0) dfs(i, -1, 0);
    if(ANS == pii(-1,-1)) {
        puts("NO");
        return;
    }
    puts("YES");
    vi c1 = C[ANS.x], c2 = C[ANS.y];
    assert(c1[0] == c1.back());
    assert(c2[0] == c2.back());
    //puts("cycles"); wypisz(cd1); wypisz(cd2);
    map<pii, int> M;
    fru(i, c1.size()) if(i) M[pii(c1[i-1], c1[i])]++;
    fru(i, c2.size()) if(i) M[pii(c2[i-1], c2[i])]++;
    di cd1, cd2;
    cd1.insert(cd1.end(), ALL(c1)-1); // skip last dup
    cd2.insert(cd2.end(), ALL(c2)-1); // skip last dup
    rotate(cd1, M);
    rotate(cd2, M);
    cd1.pb(cd1[0]); // duplicate last again
    cd2.pb(cd2[0]); // duplicate last again
    //puts("post rotate"); wypisz(cd1); wypisz(cd2);
    assert(cd1[0] == cd2[0]);
    vi ans;
    while(cd1[0] == cd2[0]) {
        ans.pb(cd1[0]);
        cd1.pop_front();
        cd2.pop_front();
    }
    reverse(ALL(cd1));
    reverse(ALL(cd2));
    cd1.pb(ans.back());
    cd2.pb(ans.back());
    //puts("ans");
    wypisz(ans);
    wypisz(cd1);
    wypisz(cd2);
}

int main() {
    solve();
    return 0;
}
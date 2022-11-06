#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
// #define int LL
#define FOR(i,a,b) for (int i = (a) ; i<= (b); i++)
#define REP(i, n) FOR(i,0,(int)(n) - 1)
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>

const int N = 605;

int t, n, m, k;
int from[N], to[N];
vector<pair<int, int> > V[N];
bool vis[N];
int inDeg[N], outDeg[N];
int ans[N];

bool DFS(int w) {
    vis[w] = true;
    if (outDeg[w] + 1 + (inDeg[w]) / 2 <= k) {
        return true;
    }
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i].first;
        int id = V[w][i].second;
        if (to[id] != u || vis[u]) {
            continue;
        }
        if (DFS(u)) {
            swap(from[id], to[id]);
            outDeg[w]--;
            inDeg[w]++;
            outDeg[u]++;
            inDeg[u]--;
            return true;
        }
    }
    return false;
}

void test() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        inDeg[i] = outDeg[i] = 0;
        V[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &from[i], &to[i]);
        V[from[i]].push_back({to[i], i});
        V[to[i]].push_back({from[i], i});
        outDeg[from[i]]++;
        inDeg[to[i]]++;
    }
    
    bool good = false;
    while (true) {
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
        }
        bool wasBad = false;
        bool corrected = false;
        for (int i = 1; i <= n; i++) {
            if (outDeg[i] + (inDeg[i] + 1) / 2 > k) {
                wasBad = true;
                if (DFS(i)) {
                    corrected = true;
                    break;
                }
            }
        }
        if (!wasBad) {
            good = true;
            break;
        }
        if (wasBad && !corrected) {
            good = false;
            break;
        }
    }
    
    if (!good) {
        for (int  i = 1; i <= m; i++) printf("0 ");
        printf("\n");
        return;
    }
    
    int ids = 0;
    for (int i = 1; i <= n; i++) {
        assert(outDeg[i] + (inDeg[i] + 1) / 2 <= k);
        int last = -1;
        for (int j = 0; j < V[i].size(); j++) {
            int u = V[i][j].first;
            int id = V[i][j].second;
            if (to[id] == i) {
                if (last == -1) {
                    last = ++ids;
                    ans[id] = last;
                } else {
                    ans[id] = last;
                    last = -1;
                }
            }
        }
    }
    
    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d", &t);
    while (t--) {
        test();
    }
    return 0;
}
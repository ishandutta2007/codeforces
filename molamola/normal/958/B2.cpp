#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define szz(x) (int)(x).size()
#define Fi first
#define Se second

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int IT_MAX = 1 << 17;

const int MX = 1000005;

vector <int> conn[100050];
vector <int> Vu;
bool dchk[100050];

vector <int> son[100050];
int mx[100050];
int dep[100050];
int par[100050];
void DFS(int n) {
    dchk[n] = true;
    mx[n] = n;
    for(auto it : conn[n]) {
        if(dchk[it]) continue;
        dep[it] = dep[n] + 1;
        son[n].push_back(it);
        par[it] = n;
        DFS(it);
        if(dep[mx[n]] < dep[mx[it]]) mx[n] = mx[it];
    }
}

priority_queue <pair<int, pii>> Hx;
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; i < N; i++) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }

    if(N == 1) return !printf("1\n");

    dchk[1] = true;
    Vu.push_back(1);
    for(i = 0; i < Vu.size(); i++) {
        for(auto it : conn[Vu[i]]) {
            if(dchk[it]) continue;
            dchk[it] = true;
            Vu.push_back(it);
        }
    }

    int r = Vu.back();
    memset(dchk, 0, sizeof(dchk));
    DFS(r);

    memset(dchk, 0, sizeof(dchk));
    dchk[r] = true;

    int ans = 1;
    for(auto it : son[r]) Hx.emplace(dep[mx[it]] - dep[it] + 1, pii(it, mx[it]));

    printf("1 ");
    for(i = 2; i <= N; i++) {
        if(Hx.empty()) break;
        int c = Hx.top().first, x = Hx.top().second.first, y = Hx.top().second.second;
        Hx.pop();
        ans += c;
        printf("%d ", ans);

        while(1) {
            dchk[y] = true;
            for(auto it : son[y]) {
                if(dchk[it]) continue;
                Hx.emplace(dep[mx[it]] - dep[it] + 1, pii(it, mx[it]));
            }
            if(y == x) break;
            y = par[y];
        }
    }
    for(; i <= N; i++) printf("%d ", N);
    return !printf("\n");
}
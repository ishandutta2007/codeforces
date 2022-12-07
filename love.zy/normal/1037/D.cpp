#include <bits/stdc++.h>
using namespace std;
#ifdef lizi
#include "local_debug.h"
#else
#define debug(...)
#endif
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define puts(x) cout << (x) << '\n'
#define endl '\n'
#define scanf _______roundgodnb
#define printf _________roundgodgay
#define getchar ________roundgodlovecalabash
#define putchar ______________roundgod
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
constexpr ll mod = (ll)1e9 + 7;
const int N = 200005;
vi e[N];

void no() {
    puts("No");
    exit(0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    if(a[1]!=1){
        no();
    }
    int tr = 0;
    multiset<int> Set;
    vector<bool> vis(n+1,false);
    vector<int> vs(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int u = a[i];
        if(i==1) {
            vis[u]=true;
        }
        tr++;
        if((i!=1&&!vis[u]) || (i!=1&&vs[u]!=*Set.begin())){
            no();
        }
        for (int v: e[u]) {
            if(vis[v]) {
                continue;
            }
            vis[v]=true;
            vs[v]=tr;
            Set.insert(tr);
        }
        if(i!=1)
            Set.erase(Set.find(vs[a[i]]));
    }
    puts("Yes");
    return 0;
}
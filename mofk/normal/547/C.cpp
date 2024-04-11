#include <bits/stdc++.h>
#define ff(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 5e5 + 1, MAXN = 2e5 + 5, INF = 1e9;

int n, m;
int d[MAX + 5];
int a[MAXN];
bool u[MAXN];
int cnt[MAX];
vi v[MAXN];

void init(void) {
    ff(i, 1, MAX) d[i] = i;
    for (int i = 2; i * i < MAX; i++) if (d[i] == i) for (int j = i * i; j < MAX; j += i) d[j] = i;
    cin >> n >> m;
    ff(i, 1, n) {
        cin >> a[i];
        int t = a[i];
        while (t > 1) {
            int p = d[t]; v[i].pb(p); while (t % p == 0) t /= p;
        }
    }
}

void process(void) {
    ll res = 0; int c = 0;
    ff(i, 1, m) {
        int x; cin >> x;
        u[x] ^= 1;
        int add = 0;
        ff(mask, 1, (1 << (int)v[x].size()) - 1) {
            int D = 1; bool b = 0;
            ff(i, 0, (int)v[x].size() - 1) if (mask & (1 << i)) { D *= v[x][i]; b ^= 1; }
            if (!u[x]) cnt[D]--;
            if (b & 1) add -= cnt[D]; else add += cnt[D];
            if (u[x]) cnt[D]++;
        }
        if (u[x]) {
            c++; res -= add;
        } else {
            c--; res += add;
        }
        cout << (1ll * c * (c - 1) / 2 - res) << "\n";
    }
}

int main(void) {
    init();
    process();
    return 0;
}
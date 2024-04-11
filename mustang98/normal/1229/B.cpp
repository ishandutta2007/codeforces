#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_log = 18, inf = 1000111222, mod = 1000000007;

vector<int> v[max_n];
ll x[max_n];
ll gc[max_n][max_log];
int p[max_n][max_log];
int n;

ll mygc(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    return __gcd(a, b);
}

void dfs(int cur, int pr) {
    gc[cur][0] = mygc(x[cur], x[pr]);
    p[cur][0] = pr;
    for (int i = 1; i < max_log; ++i) {
        p[cur][i] = p[p[cur][i - 1]][i - 1];
        gc[cur][i] = mygc(gc[cur][i - 1], gc[p[cur][i - 1]][i - 1]);
    }
    for (int to : v[cur]) {
        if (to != pr) {
            dfs(to, cur);
        }
    }
}
int p2l[max_n];
vector<int> st;
int pow2[max_n];

ll gc_path(int ifrom, int ito) {
    if (ifrom == ito) {
        return x[st[ifrom]];
    }
    int d = ito - ifrom;
    int p2 = p2l[d];
    return mygc(gc[st[ito]][p2], gc[st[ifrom + pow2[p2]]][p2]);
}

ll ans = 0;
void upd() {
    int froml = 0;
    while(true) {
        int l = froml, r = st.size();
        ll gc = gc_path(st.size() - 1 - l, st.size() - 1);
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (gc_path(st.size() - 1 - mid, st.size() - 1) == gc) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans += (gc * (l - froml + 1)) % mod;
        ans %= mod;
        if (l == st.size() - 1) {
            break;
        }
        froml = l + 1;
    }
}

void dfs2(int cur, int pr) {
    st.PB(cur);
    upd();
    for (int to : v[cur]) {
        if (to == pr) {
            continue;
        }
        dfs2(to, cur);
    }
    st.pop_back();
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", x + i);
    }
    int cur = 1, curp = 0;
    pow2[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pow2[i] = pow2[i - 1] * 2;
        if (cur * 2 <= i) {
            cur *= 2;
            ++curp;
        }
        p2l[i] = curp;
    }

    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(0, 0);
    dfs2(0, 0);
    //cout << "---- " << gc[4][0] << endl;
    cout << ans << endl;
    return 0;
}
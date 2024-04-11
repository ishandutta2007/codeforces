#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

vector<vector<int>> g, G;
int n;
mt19937 rnd(42);
const int MAXN = 105;
int cnt1, cnt2;

void gen() {
    cnt1 = cnt2 = 0;
    n = rnd() % (MAXN - 4) + 4;
    cout << "n = " << n << endl;
    g.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            g[i][j] = rnd() % 2;
//            g[i][j] = 1;
            g[j][i] = g[i][j] ^ 1;
        }
    }
}

vector<vector<int>> mem;

int ask1(int a, int b) {
    if (mem[a][b] != -1)
        return mem[a][b];
    cnt1++;
#ifdef TEST
    mem[a][b] = g[a][b];
    mem[b][a] = mem[a][b] ^ 1;
    return mem[a][b];
#else
    cout << "1 " << a << " " << b << endl;
    int res;
    cin >> res;
    mem[a][b] = res;
    mem[b][a] = mem[a][b] ^ 1;
    return res;
#endif
}

int ask2(int x, vector<int> ss) {
    if (ss.empty())
        return 0;
    for (int s : ss) {
        if (mem[x][s] == 1)
            return 1;
    }
    cnt2++;
#ifdef TEST
    for (int s : ss)
        if (g[x][s])
            return 1;
    return 0;
#else
    cout << "2 " << x << " " << (int) ss.size() << " "; for (auto s : ss) cout << s << " "; cout << endl;
    int res;
    cin >> res;
    return res;
#endif
}

int validate(vector<vector<int>> h) {
#ifdef TEST
    G = g;
    for (int i = 0; i < n; i++)
        g[i][i] = 1;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] |= g[i][k] & g[k][j];
            }
        }
    }
    return int(g == h);
#else
    cout << "3" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << h[i][j];
        }
        cout << endl;
    }
    int res;
    cin >> res;
    return res;
#endif
}

vector<int> MERGE(vector<int> a, vector<int> b) {
    vector<int> res = a;
    for (auto x : b)
        res.push_back(x);
    return res;
}

vector<vector<int>> fast(int n) {
    mem.assign(n, vector<int>(n, -1));

    vector<int> tops = {0};

    for (int v = 1; v < n; v++) {
        int bl = 0, br = (int) tops.size(), bm;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            if (ask1(v, tops[bm]))
                br = bm;
            else
                bl = bm + 1;
        }
        if (bl < br) {
            if (ask1(v, tops[bl])) {}
            else bl++;
        }
        tops.insert(tops.begin() + bl, v);
    }
    vector<vector<int>> G;
    for (int v : tops) {
        vector<int> cur = {v};
        while (!G.empty()) {
            vector<int> hlp;
            for (int it = 0; it < (int) G.size(); it++)
                for (int x : G[it])
                    hlp.push_back(x);
            if (!ask2(v, hlp))
                break;
            for (int x : G.back())
                cur.push_back(x);
            G.pop_back();
        }
        G.push_back(cur);
    }
    vector<int> pos(n);
    for (int i = 0; i < (int) G.size(); i++) {
        for (int v : G[i])
            pos[v] = i;
    }
    vector<vector<int>> h(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            h[i][j] = pos[i] <= pos[j];
        }
    }
    return h;
}

int main() {

#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
#ifdef TEST
    t = 100;
#else
    cin >> t;
#endif
    while (t--) {
#ifdef TEST
        gen();
#else
        cin >> n;
#endif
        // code here
        vector<vector<int>> h = fast(n);
        int res = validate(h);
//        assert(cnt1 <= 9 * n);
//        assert(cnt2 <= 2 * n);
#ifdef DEBUG
        cout << "cnt1: " << cnt1 << "/" << 9 * n << ", cnt2: " << cnt2 << "/" << 2 * n << "\n";
        cout << (res == 1 ? "OK" : "WA") << "\n";
        if (cnt1 > 9 * n || cnt2 > 2 * n)
            res = 0;
        if (res != 1) {
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << G[i][j];
                }
                cout << endl;
            }
            cout << "\n";
            cout << "exp\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << g[i][j];
                }
                cout << endl;
            }
            cout << "\nfnd\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << h[i][j];
                }
                cout << endl;
            }
            break;
        }
#endif
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = 50 * 1000 + 10;
const int SQR = 500;

bitset<N> state;
bitset<N> adj[SQR];
vector<int> g[5 * N];
char c[5 * N];
int x[5 * N];
int vv[5 * N];
int uu[5 * N];
int deg[5 * N];
int id[5 * N];
int a[5 * N];
int b[5 * N];

void addToHeavy(int v, int u) {
    adj[v].set(u);
}

void addToLight(int v, int u) {
    g[v].push_back(u);
}

void delFromHeavy(int v, int  u) {
    adj[v].reset(u);
}

void delFromLight(int v, int u) {
    int j = 0;
    while (j < g[v].size() && g[v][j] != u)
        j++;
    if (j == g[v].size())
        return;
    swap(g[v][j], g[v].back());
    g[v].pop_back();
}

int cntHeavy(int v) {
    return (state & adj[v]).count();
}

int cntLight(int v) {
    int res = 0;
    for (int to : g[v]) {
        if (state.test(to))
            res++;
    }
    return res;
}

bool heavy(int v) {
    return v < SQR;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m, q;
    cin >> n >> m >> q;
    state.reset();
    int o;
    cin >> o;
    for (int i = 0; i < o; i++) {
        cin >> x[i];
        x[i]--;
    }
    fill(deg, deg + n, 0);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        deg[a[i]]++;
        deg[b[i]]++;
    }
    fill(uu, uu + q, 0);
    fill(vv, vv + q, 0);
    for (int i = 0; i < q; i++)
    {
        cin >> c[i];
        while (c[i] < 'A' || c[i] > 'Z')
            cin >> c[i];
        if (c[i] == 'O' || c[i] == 'F' || c[i] == 'C') {
            cin >> uu[i];
            --uu[i];
        } else {
            cin >> uu[i] >> vv[i];
            --uu[i];
            --vv[i];
            if (c[i] == 'A') {
                deg[uu[i]]++;
                deg[vv[i]]++;
            }
        }
    }
    vector<pii> d;
    for (int i = 0; i < n; i++)
        d.push_back(pii(deg[i], i));
    sort(d.rbegin(), d.rend());
    for (int i = 0; i < n; i++)
        id[d[i].S] = i;
    for (int i = 0; i < o; i++)
        x[i] = id[x[i]];
    for (int i = 0; i < m; i++)
        a[i] = id[a[i]], b[i] = id[b[i]];
    for (int i = 0; i < q; i++)
        vv[i] = id[vv[i]], uu[i] = id[uu[i]];
    for (int i = 0; i < o; i++)
        state.set(x[i]);
    for (int i = 0; i < m; i++) {
        if (heavy(a[i]))
            addToHeavy(a[i], b[i]);
        else
            addToLight(a[i], b[i]);
        if (heavy(b[i]))
            addToHeavy(b[i], a[i]);
        else
            addToLight(b[i], a[i]);
    }
    for (int i = 0; i < q; i++) {
        switch(c[i]) {
            case 'O': state.set(uu[i]); break;
            case 'F': state.reset(uu[i]); break;
            case 'C':
                if (heavy(uu[i]))
                    cout << cntHeavy(uu[i]) << "\n";
                else
                    cout << cntLight(uu[i]) << "\n";
                break;
            case 'A':
                if (heavy(uu[i]))
                    addToHeavy(uu[i], vv[i]);
                else
                    addToLight(uu[i], vv[i]);
                if (heavy(vv[i]))
                    addToHeavy(vv[i], uu[i]);
                else
                    addToLight(vv[i], uu[i]);
                break;
            default:
                if (heavy(uu[i]))
                    delFromHeavy(uu[i], vv[i]);
                else
                    delFromLight(uu[i], vv[i]);
                if (heavy(vv[i]))
                    delFromHeavy(vv[i], uu[i]);
                else
                    delFromLight(vv[i], uu[i]);
                break;
        }
    }
    return 0;
}
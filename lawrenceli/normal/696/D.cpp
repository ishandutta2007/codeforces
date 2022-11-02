#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 205;
const ll inf = 1e18;

int n;
ll l;

int a[maxn];

string ss[maxn];

int adj[maxn][30];
char T[maxn];
int sze;
int num[maxn];

void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        int nxt = adj[cur][c - 'a'];
        
        if (nxt == -1) {
            T[sze] = c;
            adj[cur][c - 'a'] = sze;
            nxt = sze++;
        }
        cur = nxt;
    }
}

int P[maxn];
int N[maxn][30];

bool suf(string s, string t) {
    if (s.length() > t.length()) return 0;
    int d = t.length() - s.length();
    for (int i = 0; i < s.length(); i++)
        if (s[i] != t[i + d]) return 0;
    return 1;
}

string ts[maxn];

void dfs2(int v, string s = "") {
    for (int i = 0; i < n; i++)
        if (suf(ss[i], s)) num[v] += a[i];

    for (int i = 0; i < 26; i++) {
        int p = v;
        while (p && adj[p][i] == -1) p = P[p];
        N[v][i] = adj[p][i];
    }

    for (int i = 0; i < 26; i++)
        if (adj[v][i] != -1)
            dfs2(adj[v][i], s + char(i + 'a'));
}

void dfs(int v, string s = "") {
    int b = 0;
    P[v] = b;
    ts[v] = s;

    for (int i = 0; i < 26; i++)
        if (adj[v][i] != -1)
            dfs(adj[v][i], s + char(i + 'a'));
}

struct mat {
    ll a[maxn][maxn];
};

mat newmat() {
    mat m = mat();
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            m.a[i][j] = -inf;
    return m;
}

void setmax(ll& a, ll b) { if (a < b) a = b; }

mat merge(mat m1, mat m2) {
    mat m = newmat();
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            for (int k = 0; k < maxn; k++)
                setmax(m.a[i][k], m1.a[i][j] + m2.a[j][k]);
    return m;
}

mat exp(mat b) {
    mat m = newmat();
    for (int i = 0; i < maxn; i++) m.a[i][i] = 0;
    for (int i = 50; i >= 0; i--) {
        m = merge(m, m);
        if (l & (1LL<<i)) m = merge(m, b);
    }
    return m;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(adj, -1, sizeof(adj));
    sze = 1;
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
        add(ss[i]);
    }

    dfs(0);
     
    for (int i = 0; i < sze; i++) {
        int b = 0;
        for (int j = 0; j < sze; j++)
            if (j != i && ts[j].length() > ts[b].length() && suf(ts[j], ts[i]))
                b = j;
        P[i] = b;
    }

    dfs2(0);

    //for (int i = 0; i < sze; i++) cout << T[i] << ' ' << num[i] << endl;

    mat m = newmat();
    for (int i = 0; i < sze; i++)
        for (int j = 0; j < 26; j++)
            if (N[i][j] != -1)
                setmax(m.a[i][N[i][j]], ll(num[N[i][j]]));

    m = exp(m);

    ll best = -inf;
    for (int i = 0; i < maxn; i++)
        setmax(best, m.a[0][i]);
    cout << best << '\n';
}
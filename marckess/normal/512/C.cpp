#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 210;

int adj[MX][MX], res[MX][MX], p[MX], f, s, t, n;

void aug (int v, int mn) {
    if (v == s) {
        f = mn;
        return;
    }

    if (p[v] != -1) {
        aug(p[v], min(mn, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int edmond () {
    int mf = 0;
    int dist[MX];

    while (1) {
        queue<int> q;
        q.push(s);

        f = 0;
        fill(dist, dist+MX, 1e9);
        dist[s] = 0;
        fill(p, p+MX, -1);

        while (q.size()) {
            int u = q.front();
            q.pop();
            if (u == t)
                break;

            for (int v = 0; v <= n; v++) {
                if (res[u][v] > 0 && dist[v] == 1e9) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }

        aug(t, 1e9);
        if (f == 0)
            break;
        mf += f;
    }

    return mf;
}

bitset<100005> bs;
void criba () {
    bs.set();
    bs[0] = bs[1] = 0;

    for (ll i = 2; i < 100005; i++)
        if (bs[i])
            for (ll j = i*i; j < 100005; j += i)
                bs[j] = 0;
}

int a[MX], par = 0, imp = 0;
vi gra[MX], cam;
vvi resp;
 
void dfs (int u) {
    bs[u] = 1;
    cam.push_back(u);

    for (int v : gra[u])
        if (!bs[v])
            dfs(v);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    criba();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 0; j < i; j++) {
            if (bs[a[i] + a[j]]) {
                if (a[i] & 1)
                    adj[i+1][j+1] = 1;
                else
                    adj[j+1][i+1] = 1;
            }
        }

        if (a[i] & 1) {
            adj[0][i+1] = 2;
            imp++;
        } else {
            adj[i+1][n+1] = 2;
            par++;
        }
    }
    n++;

    s = 0, t = n;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            res[i][j] = adj[i][j];

    if (imp != par || edmond() != par + imp) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (res[i][j] < adj[i][j]) {
                gra[i].push_back(j);
                gra[j].push_back(i);
            }

    for (int i = 1; i < n; i++) {
        assert(gra[i].size() == 2);
        for (int x : gra[i])
            assert(bs[a[i-1] + a[x-1]]);
    }

    bs.reset();
    for (int i = 1; i < n; i++) {
        if (!bs[i]) {
            cam.clear();
            dfs(i);
            resp.push_back(cam);
        }
    }

    cout << resp.size() << endl;
    for (vi &v : resp) {
        cout << v.size();
        for (int x : v)
            cout << " " << x;
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5;
int n, m, dsu[N], u[N], v[N];
char ty[N];
bool used[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

void dsu_init() {
    fill(dsu, dsu + N, -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    dsu_init();
    rep(i, 0, m) {
        cin >> u[i] >> v[i] >> ty[i];
        if(ty[i] == 'S') {
            join(u[i], v[i]);
        }
    }
    if((n - 1) % 2 != 0) {
        cout << "-1\n";
        // cerr << "case 1" << endl;
        return 0;
    }
    vi edges;
    rep(i, 0, m) {
        if(ty[i] == 'M' && trace(u[i]) != trace(v[i])) {
            join(u[i], v[i]);
            edges.push_back(i);
            used[i] = true;
        }
    }
    if(sz(edges) > (n - 1) / 2) {
        cout << "-1\n";
        // cerr << "case 2" << endl;
        return 0;
    }
    dsu_init();
    int cnt = (n - 1) / 2 - sz(edges);
    rep(i, 0, m) {
        if(used[i]) join(u[i], v[i]);
    }
    rep(i, 0, m) {
        if(cnt > 0 && !used[i] && ty[i] == 'M' && trace(u[i]) != trace(v[i])) {
            join(u[i], v[i]);
            edges.push_back(i);
            cnt--;
        }
    }
    if(cnt != 0) {
        cout << "-1\n";
        // cerr << "case 3" << endl;
        return 0;
    }
    cnt = (n - 1) / 2;
    rep(i, 0, m) {
        if(cnt > 0 && ty[i] == 'S' && trace(u[i]) != trace(v[i])) {
            join(u[i], v[i]);
            edges.push_back(i);
            cnt--;
        }
    }
    if(cnt != 0) {
        cout << "-1\n";
        // cerr << "case 4" << endl;
        return 0;
    }
    cout << sz(edges) << '\n';
    for(int i : edges) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
}
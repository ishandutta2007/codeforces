
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2005;
int n;
ll x[N], y[N], c[N], k[N];

struct edge {
    int a, b;
    ll w;
    bool operator<(const edge &e) const {
        return w == e.w ? a == e.a ? b < e.b : a < e.a : w < e.w;
    }
};

vector<edge> vedges, mst;
int dsu[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    for(int i = 1; i <= n; i++) {
        vedges.push_back({0, i, c[i]});
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) {
                vedges.push_back({i, j, (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))});
            }
        }
    }
    sort(vedges.begin(), vedges.end());
    vector<int> p;
    ll w = 0;
    fill(dsu, dsu + N, -1);
    for(edge &e : vedges) {
        if(trace(e.a) != trace(e.b)) {
            w += e.w;
            if(e.a > 0 && e.b > 0) {
                mst.push_back(e);
            }else if(e.a == 0) {
                p.push_back(e.b);
            }else if(e.b == 0) {
                p.push_back(e.a);
            }
            join(e.a, e.b);
        }
    }
    cout << w << endl << p.size() << endl;
    for(int x : p) {
        cout << x << " ";
    }
    cout << endl;
    cout << mst.size() << endl;
    for(edge &e : mst) {
        cout << e.a << " " << e.b << endl;
    }
}
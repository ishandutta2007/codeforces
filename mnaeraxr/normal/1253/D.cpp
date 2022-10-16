#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

struct disjoint_set {
    vector<int> ds;

    disjoint_set(int n) {
        ds = vi(n, -1);
    }

    int root(int a) {
        return ds[a] < 0 ? a : ds[a] = root(ds[a]);
    }

    void join(int a, int b) {
        a = root(a), b = root(b);
        if (a == b) return;
        if (a > b) swap(a, b);
        ds[a] = b;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    disjoint_set ds(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        ds.join(u, v);
    }

    int top = -1;

    int answer = 0;

    for (int i = 0; i < n; ++i) {
        if (top < i) {
            top = ds.root(i);
        } else if (top != ds.root(i)) {
            ++answer;
            ds.join(i, top);
            top = ds.root(i);
        }
    }

    cout << answer << endl;

    return 0;
}
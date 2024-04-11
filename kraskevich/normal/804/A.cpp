#include <bits/stdc++.h>   
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
   
struct Dsu {
    vector<int> p;

    Dsu(int n): p(n) {
        iota(p.begin(), p.end(), 0);
    }

    int get(int v) {
        return p[v] == v ? p[v] : p[v] = get(p[v]);
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b)
            return false;
        p[a] = b;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << (n - 1) / 2 << endl;
    return 0;
    Dsu dsu(n);
    ll res = 0;
    int cnt = n;
    for (int i = 0; i <= n && cnt; i++) {
        for (int x = 1; x <= n; x++) {
            int to = (i - x + n + 1) % (n + 1);
            if (to != 0 && dsu.unite(x - 1, to - 1)) {
                res += i;
                cnt--;
            }
        }
    }
    cout << res << endl;
}
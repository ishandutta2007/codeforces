#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

struct Bit {
    vector<int> f;

    Bit(int n = 0): f(n) {}

    void upd(int i, int d) {
        for (; i < (int)f.size(); i = i | (i + 1))
            f[i] += d;
    }

    int get(int i) const {
        int s = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            s += f[i];
        return s;
    }

    int get(int l, int r) const {
        return get(r) - get(l - 1);
    }
};

int get_id(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'T': return 2;
        default: return 3;
    }
}

const int N = 100 * 1000 + 10;
const int ID = 4;
const int LEN = 10;

int a[N];
Bit tree[ID][LEN + 1][LEN + 1];
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
        a[i] = get_id(s[i]);
    for (int c = 0; c < ID; c++)
        for (int l = 0; l <= LEN; l++)
            for (int mod = 0; mod < l; mod++)
                tree[c][mod][l] = Bit(n);
    for (int len = 1; len <= LEN; len++)
        for (int i = 0; i < n; i++)
            tree[a[i]][i % len][len].upd(i, 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            char c;
            cin >> x >> c;
            --x;
            int new_a = get_id(c);
            for (int l = 1; l <= LEN; l++) {
                tree[a[x]][x % l][l].upd(x, -1);
                tree[new_a][x % l][l].upd(x, 1);
            }
            a[x] = new_a;
        } else {
            int l, r;
            string t;
            cin >> l >> r >> t;
            --l;
            --r;
            int m = t.length();
            int ans = 0;
            for (int mod = 0; mod < m; mod++)
                ans += tree[get_id(t[mod])][(mod + l) % m][m].get(l, r);
            cout << ans << "\n";
        }
    }
}
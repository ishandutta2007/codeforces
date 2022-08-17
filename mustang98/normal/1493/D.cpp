#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;
const int mod = 1000000007;

bool bad = 0;



struct segment_tree {
    map<int, int> m[max_n * 4];

    int get(int pos, int val ){
        auto it = m[pos].find(val);
        if (it == m[pos].end()) {
            return 0;
        }
        return it->second;
    }

    int add(int cur, int l, int r, int pos, int val) {
        if (l == r) {
            if (m[cur].find(val) == m[cur].end()) {
                m[cur][val] = 1;
            } else {
                m[cur][val]++;
            }
            return m[cur][val];
        }
        int mid = (l + r) / 2;
        int rl, rr;
        if (pos <= mid) {
            rl = add(cur * 2, l, mid, pos, val);
            if (bad) return 0;

            rr = get(cur * 2 + 1, val);
            if (rl > rr) {
                bad = 1;
                return 0;
            }
            m[cur][val] = rl;
            return rl;
        } else {
            rr = add(cur * 2 + 1, mid + 1, r, pos, val);
            if (bad) return 0;

            rl = get(cur * 2, val);
            if (rr > rl) {
                bad = 1;
                return 0;
            }
            m[cur][val] = rr;
            return rr;
        }
    }
} st;

vector<int> ff[max_n];

void init() {
    for (int i = 2; i < max_n; ++i) {
        if (!ff[i].empty()) continue;
        for (int j = i; j < max_n; j += i) {
            ff[j].push_back(i);
        }
    }
}

int main()
{
 //   freopen("input.txt", "r", stdin);
    init();
    int n, q;
    cin >> n >> q;
    ll res = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        int X = x;
        for (int d : ff[X]) {
            while (x % d == 0) {
                x /= d;
                bad = 0;
                //cout << "$ " << i << ' ' << d << endl;
                st.add(1, 0, n - 1, i, d);
                if (bad == 0) {
                    res *= d;
                    res %= mod;
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int p, x;
        scanf("%d %d", &p, &x);
        --p;
        int X = x;
        for (int d : ff[X]) {
            while (x % d == 0) {
                x /= d;
                bad = 0;
                //cout << "$ " << i << ' ' << d << endl;
                st.add(1, 0, n - 1, p, d);
                if (bad == 0) {
                    res *= d;
                    res %= mod;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
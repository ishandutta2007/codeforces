#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 200111, max_lev = 19, inf = 1000111222;

ll m[max_n];


template<typename T, int z = 1> // z = -1 for maximum
struct sparse_table {
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                mn[i][j] = __gcd(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get_gcd(int l, int r) const {
        const int lev = 31 - __builtin_clz(r - l + 1);
        return __gcd(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

sparse_table<ll> st;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
        }
        for (int i = n - 1; i > 0; --i) {
            m[i] -= m[i - 1];
            m[i] = abs(m[i]);
        }
        st.init(n, m);
        //cout << "$$ " << st.get_gcd(3, 4) << endl;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (m[i] == 1) continue;
            int l = i, r = n;
            while(l + 1 < r) {
                int mid = (l + r) / 2;
                if (st.get_gcd(i, mid) == 1) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            //cout << "% " << i << ' ' << l << endl;
            ans = max(ans, l - i + 2);
        }
        printf("%d\n", ans);
    }

    return 0;
}
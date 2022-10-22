#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> st, from(n + 1);
        vector<vector<int>> last(n + 1);
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                if (st.empty()) from[i] = 0;
                else from[i] = st.back();
                st.push_back(i);
            } else {
                while (!st.empty() && a[st.back()] + 1 != a[i])
                    st.pop_back();
                from[i] = st.back();
                st.back() = i;
            }
        }

        vector<string> res(n + 1);
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                if (from[i] == 0) res[i] = "1";
                else res[i] = res[from[i]] + ".1";
            } else {
                res[i] = res[from[i]];
                assert(from[i] > 0);
                while (!res[i].empty() && res[i].back() != '.') res[i].pop_back();
                res[i] += to_string(a[i]);
            }
        }

        for (int i = 1; i <= n; i++)
            cout << res[i] << "\n";
    }

    return 0;
}
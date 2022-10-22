#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = 252000;
const int mod = 1e9+7;
const int inf = 1e18;

int n, m, a[N], b[N];
int sa[N];
string s;
int dp[N];
int nxtd[N][20], nxtu[N][20];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    while (tests--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        for (int i=0; i<n; i++) {
            sa[i] = i;
        }
        sort(sa, sa+n, [](int i, int j) {
            return a[i] < a[j];
        });
        
        set<int> st;
        for (int i=0; i<n; i++) {
            st.insert(sa[i]);
            auto it = st.upper_bound(sa[i]);
            if (it == st.end()) {
                nxtd[sa[i]][0] = sa[i];
            } else {
                nxtd[sa[i]][0] = *it;
            }
        }

        st.clear();
        for (int i=n-1; i>=0; i--) {
            st.insert(sa[i]);
            auto it = st.upper_bound(sa[i]);
            if (it == st.end()) {
                nxtu[sa[i]][0] = sa[i];
            } else {
                nxtu[sa[i]][0] = *it;
            }
        }
        for (int j=1; j<20; j++) {
            for (int i=0; i<n; i++) {
                nxtd[i][j] = nxtd[nxtd[i][j-1]][j-1];
                nxtu[i][j] = nxtu[nxtu[i][j-1]][j-1];
            }
        }

        dp[n-1] = 0;
        for (int i=n-2; i>=0; i--) {
            dp[i] = inf;

            if (a[i+1] > a[i]) {
                // going up
                int maxr = nxtd[i][0] == i ? inf : nxtd[i][0];
                int x = i+1;
                for (int j=19; j>=0; j--) {
                    if (nxtu[x][j] <= maxr) {
                        x = nxtu[x][j];
                    }
                }
                dp[i] = dp[x] + 1;
            } else {
                // going down
                int maxr = nxtu[i][0] == i ? inf : nxtu[i][0];
                int x = i+1;
                for (int j=19; j>=0; j--) {
                    if (nxtd[x][j] <= maxr) {
                        x = nxtd[x][j];
                    }
                }
                dp[i] = dp[x] + 1;
            }
        }
        cout << dp[0] << endl;
    }
}
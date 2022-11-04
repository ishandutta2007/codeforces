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

int gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int n, l[305], c[305];
int dp[305][10005];
set<int> st;
vi a;

int obtRes(int i, int j) {
    if (j == 1)
        return 0;

    if (i == n)
        return 1e9;

    int &res = dp[i][j];
    if (res != -1)
        return res;

    return res = min(
        obtRes(i+1, j), 
        obtRes(i+1, lower_bound(a.begin(), a.end(), gcd(a[j], l[i]) ) - a.begin()) + c[i]);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    a.push_back(1);
    a.push_back(0);
    st.insert(1);
    st.insert(0);

    for (int i = 0; i < n; i++) {
        for (int x : st) {
            int d = gcd(x, l[i]);

            if (st.find(d) == st.end()) {
                st.insert(d);
                a.push_back(d);
            }
        }
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < a.size(); j++)
            dp[i][j] = -1;

    int res = obtRes(0, 0);

    if (res >= 1e9)
        cout << -1 << endl;
    else
        cout << res << endl;

    return 0;
}
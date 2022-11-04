#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int dp[1000005];
vector<int> st[10];

int f (int n) {
    int res = 1;
    while (n) {
        if (n%10)
            res *= n % 10;
        n /= 10;
    }
    return res;
}

int g (int n) {
    if (n < 10)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = g(f(n));
}

void precal () {
    for (int i = 1; i <= 1e6; i++) {
        st[g(i)].push_back(i);
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    fill (dp, dp+1000005, -1);
    precal();

    int q, l, r, k;

    cin >> q;
    while (q--) {
        cin >> l >> r >> k;
        cout << upper_bound(st[k].begin(), st[k].end(), r)
                - lower_bound(st[k].begin(), st[k].end(), l) << endl;
    }

    return 0;
}
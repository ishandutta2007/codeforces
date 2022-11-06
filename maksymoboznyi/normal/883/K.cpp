#include<bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int s[N], g[N], n;
int L[N], R[N];


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> g[i];
    int l = s[1], r = s[1] + g[1];
    L[1] = l;
    R[1] = r;
    for (int i = 2; i <= n; i++) {
        int l1 = s[i], r1 = s[i] + g[i];
        int nl = max(l - 1, l1), nr = min(r + 1, r1);
        if (nl > nr) {
            cout << -1;
            return 0;
        }
        l = nl;
        r = nr;
        L[i] = l;
        R[i] = r;
    }
    vector<int> ans;
    ans.pb(R[n]);
    int cur = R[n];
    int sum = cur - s[n];
    for (int i = n - 1; i > 0; i--) {
        if (cur + 1 <= R[i])
            cur = cur + 1;
        else if (cur <= R[i])
            cur = cur;
        else
            cur = cur - 1;
        ans.pb(cur);
        sum += cur - s[i];
    }
    reverse(ans.begin(), ans.end());
    cout << sum << "\n";
    for (auto x : ans)
        cout << x << ' ';
    return 0;
}
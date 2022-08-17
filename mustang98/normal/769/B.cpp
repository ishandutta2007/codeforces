#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 105;
pair<int, int> m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, sum = 0, nxt = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i].F;
        m[i].S = i;
        sum += m[i].F;
    }
    if (m[0].F == 0 || sum < n - 1) {
        cout << "-1\n";
        return 0;
    }
    sort(m + 1, m + n);
    reverse(m + 1, m + n);
    vector<pair<int, int> > ans;
    for (int cur = 0; cur < n; ++cur) {
        int msgcnt = m[cur].F;
        while (msgcnt--) {
            ans.pb(mp(m[cur].S, m[nxt].S));
            nxt++;
            if (nxt == n) break;
        }
        if (nxt == n) break;
    }
    cout << ans.size() << endl;
    for (pair<int, int> p : ans) {
        cout << p.F + 1 << ' ' << p.S + 1 << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222, max_v = 1e6 + 100;

vector<vector<int>> v;
int m[max_v + 3];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    ll ans = 0;
    cin >> n;
    ll cnth = 0;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        vector<int> cur;
        for (int i = 0; i < l; ++i) {
            int a;
            cin >> a;
            cur.PB(a);
        }
        bool has = false;
        for (int i = 0; i + 1 < cur.size(); ++i) {
            if (cur[i] < cur[i + 1]) {
                has = true;
                break;
            }
        }
        if (has) {
            ++cnth;
        } else {
            v.PB(cur);
        }
    }
    n -= cnth;
    ans = cnth * cnth + cnth * n * 2;
    for (int i = 0; i < n; ++i) {
        m[v[i][0]]++;
    }
    for (int i = max_v - 1; i >= 0; --i) {
        m[i] += m[i + 1];
    }
    for (int i = 0; i < n; ++i) {
        ans += m[v[i].back() + 1];
    }
    cout << ans << endl;

    return 0;
}
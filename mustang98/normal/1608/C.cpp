#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int s[max_n];
pair<int, int> m[max_n];
int n;
vector<int> c;
vector<int> c2;


void compress() {
    c.clear();
    c2.clear();
    for (int i = 0; i < n; ++i) {
        c.emplace_back(m[i].F);
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n; ++i) {
        m[i].F = lower_bound(c.begin(), c.end(), m[i].F) - c.begin();
    }
    for (int i = 0; i < n; ++i) {
        c2.emplace_back(m[i].S);
    }
    sort(c2.begin(), c2.end());
    for (int i = 0; i < n; ++i) {
        m[i].S = lower_bound(c2.begin(), c2.end(), m[i].S) - c2.begin();
    }
}

int mx[max_n];

void solve() {
    compress();
    sort(m, m + n);
    /*vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        v.emplace_back(m[i].S, m[i].F);
    }
    sort(v.begin(), v.end());
    int mx = -1;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, v[i].S);
        to[v[i].S] = mx;
    }*/
    for (int i = 0; i < n; ++i) {
        mx[i] = m[i].S;
        if (i) {
            mx[i] = max(mx[i], mx[i - 1]);
        }
    }
    int ans = n - 1;
    int mn = m[n - 1].S;
    for (int i = n - 2; i >= 0; --i) {
        if (mx[i] < mn) {
            break;
        }
        ans = i;
        mn = min(mn, m[i].S);
    }
    int from = c[ans];
    for (int i = 0; i < n; ++i) {
        if (s[i] >= from) {
            cout << "1";
        } else {
            cout << "0";
        }

    }
    cout << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            mx[i] = -1;
            cin >> s[i];
            m[i].F = s[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> m[i].S;
        }
        solve();
    }

    return 0;
}
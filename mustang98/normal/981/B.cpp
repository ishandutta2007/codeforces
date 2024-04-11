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

map<int, int> ca, cb;
set<int> s;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, x;
        cin >> a >> x;
        ca[a] = x;
        s.insert(a);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int b, x;
        cin >> b >> x;
        cb[b] = x;
        s.insert(b);
    }
    ll ans = 0;
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        int ind = *it;
        if (ca.find(ind) == ca.end()) {
            ans += cb[ind];
        } else if (cb.find(ind) == cb.end()) {
            ans += ca[ind];
        } else {
            ans += max(ca[ind], cb[ind]);
        }

    }

    cout << ans;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s = "codeforces";
    int sz = (int) s.size();

    vector<int> cnt(sz, 1);

    ll n;
    cin >> n;

    while (1) {
        ll ml = 1;
        for (int i = 0; i < sz; i++) {
            ml *= cnt[i];
        }
        if (ml >= n)
            break;
        int p = 0;
        for (int i = 0; i < sz; i++) {
            if (cnt[i] < cnt[p])
                p = i;
        }
        cnt[p]++;
    }

    for (int i = 0; i < sz; i++) {
        cout << string(cnt[i], s[i]);
    }
    cout << "\n";

    return 0;
}
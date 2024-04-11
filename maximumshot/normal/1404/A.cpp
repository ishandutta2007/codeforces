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

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> type(k, -1);
        int ok = 1;
        for (int i = 0; i < n; i++) {
            int j = i % k;
            if (s[i] == '?')
                continue;
            int x = s[i] - '0';
            if (type[j] != -1 && type[j] != x) {
                ok = 0;
                break;
            }
            type[j] = x;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            int j = i % k;
            if (type[j] != -1)
                s[i] = '0' + type[j];
        }
        int mn = 0, mx = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == '1')
                mn++, mx++;
            else if (s[i] == '0')
                mn--, mx--;
            else
                mx++, mn--;
        }
        if (mx < 0 || mn > 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
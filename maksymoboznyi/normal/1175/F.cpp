#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 5e5 + 5;

mt19937 rnd(time(NULL));

bool operator ==(pair<int, int> &a, pair<int, int> &b) {
    return a.first == b.first && a.second == b.second;
}

pair<int, int> operator ^(pair<int, int> &a, pair<int, int> &b) {
    return make_pair(a.first ^ b.first, a.second ^ b.second);
}

int n;
pair<int, int> h[N];

void get_random_hash(int pos) {
    h[pos].first = rnd();
    h[pos].second = rnd();
}

int a[N];
pair<int, int> ph[N], pref[N];

pair<int, int> f(int l, int r) {
    return pref[r] ^ pref[l - 1];
}

signed main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], get_random_hash(i), ph[i] = (ph[i - 1] ^ h[i]);
    for (int i = 1; i <= n; i++)
        pref[i] = (pref[i - 1] ^ h[a[i]]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 1) {
            int r = i + 1, len = a[i + 1];
            for (; a[r] != 1 && r <= n; r++) {
                if (r >= len && (pref[r] ^ pref[r - len]) == ph[len])
                    ans++;
                len = max(len, a[r + 1]);
            }
            ans++;
    }
    for (int i = 2; i <= n; i++)
        if (a[i] == 1) {
            int r = i - 1, len = a[i - 1];
            for (; a[r] != 1 && r > 0; r--) {
                if (r + len - 1 <= n && (pref[r + len - 1] ^ pref[r - 1]) == ph[len])
                    ans++;
                len = max(len, a[r - 1]);
            }
        }
    cout << ans;
    return 0;
}
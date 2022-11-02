#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 20 * 1000;
const int UP = 10 * 1000 + 10;

int bit_cnt[N];
ll cnt[N];

int main() {
#if FALSE
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    for (int i = 0; i < N; i++)
        bit_cnt[i] = __builtin_popcount(i);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    ll res = 0;
    if (k == 0) {
        for (int i = 0; i < UP; i++)
            res += cnt[i] * (cnt[i] - 1) / 2;
    } else {
        for (int i = 0; i < UP; i++)
            for (int j = i + 1; j < UP; j++)
                if (bit_cnt[i ^ j] == k)
                    res += cnt[i] * cnt[j];
    }
    cout << res << endl;
}
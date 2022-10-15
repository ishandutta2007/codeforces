#include <bits/stdc++.h>
using namespace std;

#define int long long

#define mod 1000000007

bool mem1;

// int Pow(int a, int x) {
//     int ans = 1;
//     while (x) {
//         if (x & 1) ans = ans * a % mod;
//         a = a * a % mod, x >>= 1;
//     }
//     return ans;
// }

// vector<int> prime;
// vector<bool> notPrime;
// void findPrime(int maxv) {
//     prime.clear();
//     notPrime.resize(maxv);
//     notPrime[1] = true;
//     for (int i = 1; i < maxv; i++) {
//         if (!notPrime[i]) prime.push_back(i);
//         for (auto j : prime) {
//             if (i * j >= maxv) break;
//             notPrime[i * j] = true;
//             if (i % j == 0) break;
//         }
//     }
//     return;
// }

int a[200005];
int even[70];

int get2(int x) {
    int ans = 0;
    while (x % 2 == 0) x /= 2, ans++;
    return ans;
}

void solve(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], even[get2(a[i])]++;
    int ans = n;
    for (int i = 0; i < 70; i++) ans = min(ans, n - even[i]);
    cout << ans << endl;
    for (int t = 0; t < 70; t++)
        if (ans == n - even[t]) {
            for (int i = 1; i <= n; i++)
                if (get2(a[i]) != t) cout << a[i] << ' ';
            cout << endl;
            return;
        }
    return;
}

bool mem2;

signed main() {
#ifdef MACESUTED
    cerr << "Memory: " << abs(&mem1 - &mem2) / 1024. / 1024. << "MB" << endl;
#endif

    int _ = 1;
    while (_--) solve();

#ifdef MACESUTED
    cerr << "Time: " << clock() * 1000. / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}
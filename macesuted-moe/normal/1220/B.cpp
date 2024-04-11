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

#define maxn 1005

int a[maxn][maxn], b[maxn];

void solve(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    b[1] = sqrt(a[1][2] * a[1][3] / a[2][3]);
    for (int i = 2; i <= n; i++) b[i] = a[1][i] / b[1];
    for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    cout << endl;
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
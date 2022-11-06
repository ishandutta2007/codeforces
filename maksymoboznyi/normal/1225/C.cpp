#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 1e6 + 6;

long long k;

int k_1(int x) {
    int ans = 0;
    int i = 2;
    while (x > 0) {
        ans += x % i;
        x /= i;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, p;
    cin >> n >> p;
    for (int kol = 1; kol <= 1000000; kol++) {
        long long x = n - kol * p;
        if (k_1(x) <= kol && x >= kol) {
            cout << kol;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
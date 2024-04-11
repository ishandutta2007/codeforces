#include <bits/stdc++.h>
#define int long long
using namespace std;

long long n, m, k;

int f(int n) {
    return max(1ll*0, n % k + n / k * (k - 1));
}

int gp(int a, int b) {
    int res = 1;
    while (b > 0)
    if (b % 2 == 0) {
        a *= a;
        a %= 1000000009;
        b /= 2;
    } else {
        res *= a;
        res %= 1000000009;
        b--;
    }
    return res;
}

signed main()
{
    cin >> n >> m >> k;
    int kol = n % k + n / k * (k - 1);
    if (kol >= m)
    {
        cout << m % 1000000009;
        return 0;
    }
    int l = 0, r = m;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (mid + f(n - mid - 1) >= m)
            r = mid;
        else
            l = mid;
    }
    int pos = r;
    //cout << pos << ' ' << 3 + f(n - 4) << endl;
    int x = pos / k;
    int M = 1e9 + 9;
    int d = ((gp(2, x + 1)*k%M - 2*k%M)%M +M)%M;
    //cout << d << endl;
    d += pos % k + m - pos;
    d += M;
    d %= M;
    cout << d % 1000000009;
    return 0;
}
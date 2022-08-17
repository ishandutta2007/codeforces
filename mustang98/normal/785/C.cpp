#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int max_n = 200111, inf = 1000111222;

ull f(ull a)
{
    return a * (a + 1);
}

int ans(int n, int m)
{
    int cur = n;
    for (int i = 1; true ;++i) {
        cur = min(n, cur + m);
        cur -= i;
        if (cur <= 0) return i;
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    //cout << ans(n, m) << endl;
    if (m + 1 >= n) {
        cout << n;
        return 0;
    }
    ll start = n - m;
    //cout << start << endl;
    ull l = max(0.0, round(sqrt(2 * start)) - 100);
    ull r = round(sqrt(2 * start)) + 100;
    for (ull i = l + 1; i <= r; ++i) {
        if (f(i - 1) < 2 * start && f(i) >= 2 * start) {
            cout << m + i;
            return 0;
        }
    }

    return 0;
}
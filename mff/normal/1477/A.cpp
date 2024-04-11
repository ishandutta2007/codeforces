#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

long long gcd(long long a, long long b)
{
    while (b > 0)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());

        auto x = a[0];

        k -= x;
        long long g = 0;

        for (auto y : a)
            g = gcd(g, y - x);

        cout << (abs(k) % g == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}
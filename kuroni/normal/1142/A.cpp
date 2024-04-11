#include <bits/stdc++.h>
using namespace std;

const long long INF = 1E18 + 7;

int n, k, a, b;
long long mi = INF, ma = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> a >> b;
    long long sz = 1LL * n * k;
    for (int i = 0; i < n; i++)
    {
        vector<long long> fi = {a, k - a}, se = {1LL * i * k + b, 1LL * (i + 1) * k - b};
        for (long long &u : fi)
            for (long long &v : se)
            {
                long long dis = (v - u + sz) % sz;
                if (dis == 0)
                    dis = sz;
                mi = min(mi, sz / __gcd(sz, dis));
                ma = max(ma, sz / __gcd(sz, dis));
            }
    }
    cout << mi << " " << ma << '\n';
}
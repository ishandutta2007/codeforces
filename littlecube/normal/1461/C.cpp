#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a[100000], min = 0;
        double p = 0.0;
        vector<double> P;
        cin >> n >> m;
        min = n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 0; i--)
            if (i + 1 == a[i])
                min = i;
            else
                break;
        for (int i = 0; i < m; i++)
        {
            int index;
            double prop;
            cin >> index >> prop;
            if (index >= min)
                P.emplace_back(prop);
        }
        for (auto i : P)
            p += (1.0 - p) * i;
        if (min == 0)
            cout << "1.000000\n";
        else
            cout << fixed << setprecision(6) << p << '\n';
    }
}
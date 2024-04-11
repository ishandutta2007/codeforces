#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, t[50];
        map<int, bool> d;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> t[i];
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                d[(t[j] - t[i])] = 1;
        cout << d.size() << '\n';
    }
}
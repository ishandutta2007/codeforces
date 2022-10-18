#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

void solve()
{
    int n[4];
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    cout << max(n[0] + n[1], n[2] + n[3]) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
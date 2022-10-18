#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll n, m, a;
    cin >> n >> m >> a;
    cout << ((n - 1) / a + 1) * ((m - 1) / a + 1) << '\n';
}
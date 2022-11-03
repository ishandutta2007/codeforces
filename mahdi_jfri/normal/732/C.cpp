#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e8;
const int maxn = 5e3 + 1;
int main()
{
    ll a, b , c;
    cin >> a >> b >> c;
    ll k = max(a, max(b , c));
    if(a == k)
        a--;
    if(b == k)
        b--;
    if(c == k)
        c--;
    k--;
    cout << k - a + k - b + k - c;
}
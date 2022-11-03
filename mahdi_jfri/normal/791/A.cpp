#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
    ll a , b , ans = 0;
    cin >> a >> b;
    while(a <= b)
    {
        a *= 3;
        b *= 2;
        ans++;
    }
    cout << ans;
}
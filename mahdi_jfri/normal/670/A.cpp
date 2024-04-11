#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
    ll n , res = 0;
    cin >> n;
    if(n <= 2)
    {
        cout << "0 " << n;
        return 0;
    }
    res = n / 7 * 2;
    cout << (n / 7) * 2 + max((n % 7) - 5 , (ll)0) << " " << (n - 2) / 7 * 2 + max((n - 2) % 7 - 5 ,(ll) 0) + 2;
}
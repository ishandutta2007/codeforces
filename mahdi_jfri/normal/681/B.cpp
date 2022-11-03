#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
    ll n;
    cin >> n;
    for(ll i = 0; i * 1234567 <= n; i++)
        for(ll j = 0; i * 1234567 + j * 123456 <= n; j++)
            if((n - i * 1234567 - j * 123456) % 1234 == 0)
            {
                cout << "YES";
                return 0;
            }
    cout << "NO";
}
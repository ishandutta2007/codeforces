#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
ll res;
int main()
{
    ll n;
    cin >> n;
    ll x = 1;
    for(int i = 1; i <= 10; i++)
    {
        if(x <= n / 10)
        {
            res += x * i * 9;
            x *= 10;
        }
        else
        {
            res += (n - x + 1) * i;
            break;
        }
    }
    cout << res << endl;
}
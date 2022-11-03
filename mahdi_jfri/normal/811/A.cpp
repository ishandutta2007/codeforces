#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e3 + 20;
int main()
{
    ll a , b;
    cin >> a >> b;
    for(ll i = 1; ; i++)
    {
        if(i & 1)
            a -= i;
        else
            b -= i;
        if(a < 0)
        {
            cout << "Vladik";
            return 0;
        }
        else if(b < 0)
        {
            cout << "Valera";
            return 0;
        }
    }
}
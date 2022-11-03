#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int maxn = 1e5+20;
int res;
int main()
{
    ll n;
    cin >> n;
    while (n > 0)
    {
        if(n%10 == 7 || n%10 == 4)
            res++;
        n/=10;
    }
    if(res == 7 || res == 4)
        cout <<"YES";
    else
        cout << "NO";
}
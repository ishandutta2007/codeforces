#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll b;
int main()
{
    ll a;
    cin >> a;
    ll res=0;
    res = a/2;
    if(a&1)
        res-=a;
    cout << res;
}
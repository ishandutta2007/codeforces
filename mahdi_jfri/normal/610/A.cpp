#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
int a;
ll res;
int main()
{
    ll n;
    cin >> n;
    if(n&1)
    {
        res=0;
    }
    else
    {
        res=n/2-1;
        res/=2;
    }
    cout<<res;
}
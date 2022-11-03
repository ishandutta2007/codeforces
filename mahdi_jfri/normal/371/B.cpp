#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
bool check(int a)
{
    bool x = true;
    while(x)
    {
        x=false;
        if(a % 5 == 0)
        {
            x= true;
            a/=5;
        }
        else if(!(a&1))
        {
            x=true;
            a/=2;
        }
        else if(!(a%3))
        {
            x=true;
            a/=3;
        }
    }
    return ((a == 1)?1:0);
}
int solve(int c)
{
    ll res= 0;
    while(c!=1)
        {
            if(c % 5 == 0)
            {
                c/=5;
                res++;
            }
            else if(!(c&1))
            {
                c/=2;
                res++;
            }
            else if(!(c%3))
            {
                c/=3;
                res++;
            }
        }
    return res;
}
int main()
{
    ll a , b;
    cin >> a >> b;
    ll c =a/ __gcd(a,b);
    ll d = b/ __gcd(a,b);
    ll gcd=__gcd(a,b);
    if(!check(c) || !check(d))
    {
        cout << -1;
    }
    else
    {
        cout << solve(c) + solve(d);
        return 0;
    }
}
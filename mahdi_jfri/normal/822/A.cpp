#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) (x & -(x))
#define BIT(a,b) ((ll)((a)&(1(b)))==0 ? false : true)

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    ll a,b;
    cin>>a>>b;

    if (b>a)
    {
        swap(a , b);
    }

    ll u=1;

    for(ll i=1;i<=b;i++)
    {
        u*=i;
    }

    cout<<u;
}
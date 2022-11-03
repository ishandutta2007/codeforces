
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

#define LB(x) (x & (-x))
#define BIT(a,b) ((ll)(a&(1<<b))==0 ? false : true)

const ll MAXN=1e6+10;

bool check[MAXN];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    ll n,k,res=1,y=1;
    cin>>n>>k;

    ll u=1;
    k = min(k , n - k);
    while (!check[u])
    {
        check[u]=true;

        u+=k;

        if (u>n)
        {
            u-=n;
            y+=2;
            res--;
        }

        res+=y;

        if (u==1)
        {
            res--;
        }

        cout<<res<<" ";
    }
}
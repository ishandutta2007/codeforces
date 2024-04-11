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
#define BIT(a,b) ((ll)((a)&(1<<(b)))==0 ? false : true)

const ll MAXN=1e6+10;

ll a[MAXN];
ll f[MAXN];
ll last[MAXN];

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(0);

  ll n , res=0;
  cin>>n;

  for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    fill(f , f+MAXN , n);
    fill(last , last+MAXN , n);

    for(ll i=0;i<n;i++)
    {
        if (last[a[i]]!=n)
        {
            f[last[a[i]]]=i;
        }

        last[a[i]]=i;
    }

    for(ll i=0;i<n;i++)
    {
        res+=(f[i]-i)*(i+1)*2-1;
    }

    cout<<fixed<<setprecision(10)<<(ld)(res)/(n*n);
}
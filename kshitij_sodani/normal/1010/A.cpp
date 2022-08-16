#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define vll vector<ll>

using namespace std;

const ll N = 1e3+10;
const ll MOD = 1e9+7;
const ld EPS = 1e-7;
ll n;
ld m;
ld a[N];
ld b[N];

bool check(ld x)
{
    for(int i = 1;i<=(n-1);i++)
    {
       ld lift = (x + m);
       lift = (x+m)/a[i];
       x -= lift;
       if(x < 0) return false;
       lift = (x+m);
       lift = (x+m)/ b[i+1];
       x-=lift;
       if(x<0) return false;
    }

    ld lift = (x+m)/a[n];
    x-=lift;
    if(x<0) return false;
    lift = (x+m)/b[1];
    x-=lift;
    if(x<0)return false;


    if(x>=0) return true;
    return false;
}

int main()
{

    cin >> n;
    cin >> m;

    for(int i =1;i<=n;i++) cin >> a[i];
    for(int i =1;i<=n;i++) cin >> b[i];


    ld l = 0,r = 1e9+1;
    ld ans = 1e10;
    
    while((l+EPS)< r)
    {
        ld mid = (ld)0.5 * (l+r);
        if(check(mid))
        {
            ans = mid;
            r = mid;
        }
        else l = mid;
    }
    if(ans==(ld)1e10) return cout << -1 << endl,0;
    cout<<setprecision(20) << ans<<endl;    

    return 0;
}
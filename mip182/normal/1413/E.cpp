#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout<<#x<<"="<<x<<", ";}
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 2e9+11;

void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a>b*c)
    {
        cout<<-1<<'\n';
        return;
    }
    if (c<=d)
    {
        cout<<a<<'\n';
        return;
    }
    __int128 ans=a;
    auto f = [&](__int128 k)
    {
        __int128 total=(k+1)*a;
        __int128 l=(k*d-c>=0?(k*d-c)/d:-1);
        total-=b*c*(l+1);
        total-=b*((k-l)*k*d-d*l*(k-l)-d*(k-l)*(k-l+1)/2);
        ans=max(ans,total);
        return total;
    };
    __int128 le=0,re=INF;
    while (re-le>3)
    {
        __int128 mid1=(2*le+re)/3,mid2=(le+2*re)/3;
        if (f(mid1)<f(mid2))
            le=mid1;
        else
            re=mid2;
    }
    for (ll i=le;i<=re;i++)
        f(i);
    cout<<((ll)ans)<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}
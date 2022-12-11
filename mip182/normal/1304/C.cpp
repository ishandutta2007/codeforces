#include <bits/stdc++.h>
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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
bool inter(ll l,ll r,ll l1,ll r1)
{
    if (min(r,r1)-max(l,l1)>=0)
        return true;
    else
        return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int q;
    cin>>q;
    while (q--)
    {
        ll n,m;
        cin>>n>>m;
        ll t,l,h;
        cin>>t>>l>>h;
        ll low=m-t,up=m+t;
        bool ok=true;
        if (!inter(low,up,l,h))
            ok=false;
        low=max(low,l);
        up=min(h,up);
        ll wast=t;
        for (int i=1;i<n;i++)
        {
            cin>>t>>l>>h;
            ll wasx=t;
            t-=wast;
            wast=wasx;
            if (low>up)
                ok=false;
            low-=t,up+=t;
            if (!inter(low,up,l,h))
                ok=false;
            low=max(low,l);
            up=min(h,up);
        }
        if (ok)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }




}
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
    mt19937 rng(time(0));
    int n;
    cin>>n;
//    n=3;
    vector <int> a(n);
    rep(i,n)
    {
        cin>>a[i];
//        a[i]=rng()%8;
    }
//    for (auto to:a)
//        cout<<to<<" ";
//    cout<<'\n';
    int x=0;
    for (auto to:a)
        x^=to;
    if (n%2==0&&x!=0)
    {
        cout<<"NO\n";
        return;
    }
    vector <vector <int> > ans;
    auto does = [&](int i,int j,int k)
    {
        ans.pb({i,j,k});
        int x=(a[i]^a[j]^a[k]);
        a[i]=x;
        a[j]=x;
        a[k]=x;
    };
    if (n&1)
    {
        for (int i=1;i<n;i+=2)
        {
            does(0,i,i+1);
        }
        assert(a[0]==x);
    }
    int now=1;
    while (n-1-now+1>=3)
    {
        if (n%2==0)
        does(now,now+1,now+2);
        does(0,now,now+1);
        now+=2;
    }
//    cout<<ans.size()<<'\n';
    if (n&1)
    {
        assert(now==n-2);
        ans.pb({0,n-2,n-1});
        does(0,n-2,n-1);
        assert(ans.size()<=n);
        cout<<"YES\n";
        cout<<ans.size()<<'\n';
        for (auto &to:ans)
            cout<<to[0]+1<<" "<<to[1]+1<<" "<<to[2]+1<<'\n';
    }
    else
    {
        assert(ans.size()<=n);
        assert(now==n-1);
        assert(a[0]==a[n-1]);
        cout<<"YES\n";
        cout<<ans.size()<<'\n';
        for (auto &to:ans)
            cout<<to[0]+1<<" "<<to[1]+1<<" "<<to[2]+1<<'\n';
    }
//    for (auto to:a)
//        cout<<to<<" ";
//    cout<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}
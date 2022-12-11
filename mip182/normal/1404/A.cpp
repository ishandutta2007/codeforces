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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN
#define itn int
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=0;i<k;i++)
    {
        int x=i;
        int a=0,b=0;
        while (x<n)
        {
            if (s[x]=='?') {
                x+=k;
                continue;
            }
            if (s[x]=='1')
                a++;
            else
                b++;
            x+=k;
        }
        if (a>0&&b>0)
        {
            cout<<"NO\n";
            return;
        }
        if (a==0&&b==0)
            continue;
        if (a>0)
        {
            for (x=i;x<n;x+=k)
                s[x]='1';
        }
        else
        {
            for (x=i;x<n;x+=k)
                s[x]='0';
        }
    }
    int d=0,a=0,b=0;
    for (int i=0;i<k;i++)
    {
        if (s[i]=='?')
            d++;
        else
        {
            if (s[i]=='1')
                a++;
            else
                b++;
        }
    }
    int mx=max(a,b);
    if (mx>k/2)
    {
        cout<<"NO\n";
        return;
    }
    cerr<<s<<'\n';
    cout<<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
    cin>>_t;
//    _t=1;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}
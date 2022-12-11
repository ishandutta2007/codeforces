//#define _GLIBCXX_DEBUG
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
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    if (s.size()!=t.size())
    {
        cout<<-1;
        return 0;
    }
    int cntt=0,cnt1=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='0')
            cntt++;
        if (t[i]=='0')
            cnt1++;
    }
    if (cntt!=cnt1)
    {
        cout<<-1;
        return 0;
    }
    vector <int> a;
    for (int i=0;i<n;i++)
    {
        if (s[i]!=t[i])
            a.pb(s[i]-'0');
    }
    int zero=0,one=0;
    for (auto to:a)
    {
        if (to==1)
        {
            if (zero>0)
                zero--,one++;
            else
                one++;
        }
        else
        {
            if (one>0)
                one--,zero++;
            else
                zero++;
        }
    }
    cout<<zero+one;


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}
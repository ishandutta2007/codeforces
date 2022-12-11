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
    ll k;
    cin>>k;
    string s="codeforces";
    int n=s.size();
    ll l=n,r=1000;
    ll f=n;
    while (l<=r)
    {
        ll mid=((l+r)>>1);
        ll x=mid/n;
        ll now=1;
        bool ok=false;
        for (int i=0;i<mid%n;i++)
        {
            now*=x+1;
            if (now>=k)
            {
                ok=true;
                break;
            }
        }
        if (ok)
        {
            f=mid;
            r=mid-1;
            continue;
        }
        for (int i=0;i<n-mid%n;i++)
        {
            now*=x;
            if (now>=k)
            {
                ok=true;
                break;
            }
        }
        if (ok)
        {
            f=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    ll x=f/n;
    int cur=0;
    for (int i=0;i<f%n;i++)
    {
        for (int j=0;j<x+1;j++)
            cout<<s[cur];
        cur++;
    }
    for (int i=0;i<n-f%n;i++)
    {
        for (int j=0;j<x;j++)
            cout<<s[cur];
        cur++;
    }


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}
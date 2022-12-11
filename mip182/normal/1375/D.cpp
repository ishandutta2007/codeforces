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
int mex(vi a)
{
    a.pb(1e9);
    sort(all(a));
    a.resize(unique(all(a))-a.begin());
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=i)
            return i;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
    cin>>_t;
    while (_t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        rep(i,n)
        cin>>a[i];
        vector <int> ans;
        while (true)
        {
            bool ok=true;
            vector <bool> used(n+1);
            for (int i=0;i<n;i++)
            {
                if (used[a[i]])
                {
                    ok=false;
                    ans.pb(i+1);
                    a[i]=mex(a);
                    break;
                }
                used[a[i]]=1;
            }
            if (ok)
                break;
        }
        vector <bool> used(n+1);
        for (int i=0;i<n;i++)
            used[a[i]]=true;
        int x;
        for (int i=0;i<=n;i++)
        {
            if (!used[i])
                x=i;
        }
        while (true)
        {
            vi b=a;
            sort(all(b));
            if (a==b)
                break;
            if (x>=n-1)
            {
                if (a[n-1]==2*n-1-x)
                {
                    for (int i=0;i<n;i++)
                    {
                        if (a[i]!=i)
                        {
                            ans.pb(i+1);
                            int y=a[i];
                            a[i]=x;
                            x=y;
                            break;
                        }
                    }
                }
                else
                {
                    ans.pb(n);
                    int y=a[n-1];
                    a[n-1]=x;
                    x=y;
                }
            }
            else
            {
                ans.pb(x+1);
                int y=a[x];
                a[x]=x;
                x=y;
            }
        }
//        for (auto to:a)
//            cout<<to<<" ";
//        cout<<'\n';
        cout<<ans.size()<<'\n';
        for (auto to:ans)
            cout<<to<<" ";
        cout<<'\n';

    }
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}
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
int mex(vi &a)
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
int f[101];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    f[1]=0;
    for (int i=2;i<=100;i++)
    {
        int w=i;
        int cnt=0;
        while (w%2==0)
            w/=2,cnt++;
        vi a;
        a.pb(f[i-1]);
        for (int j=1;j*j<=w;j++)
        {
            if (w%j==0)
            {
                if (j>1)
                    a.pb(f[i/j]);
                if (w/j>1)
                    a.pb(f[i*j/w]);
            }
        }
        f[i]=mex(a);
     //   if (f[i]==0)
      //  cout<<i<<" "<<cnt<<" "<<w<<'\n';
    }
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if (n==1)
        {
            cout<<"FastestFinger\n";
            continue;
        }
        if (n==2)
        {
            cout<<"Ashishgup\n";
            continue;
        }
        int w=n;
        int cnt=0;
        while (w%2==0)
            cnt++,w/=2;
        bool ok=true;
        for (int i=2;i*i<=w;i++)
        {
            if (w%i==0)
            {
               ok=false;
               break;
            }
        }
        if ((cnt==1&&ok)||(w==1))
            cout<<"FastestFinger"<<'\n';
        else
            cout<<"Ashishgup"<<'\n';
    }

    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}
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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while (t--)
    {
    int n;
    cin>>n;
    vector <int> a(2*n);
    rep(i,2*n)
    cin>>a[i];
    int one=0,two=0;
    for (int i=0;i<2*n;i++)
    {
        if (a[i]==1)
            one++;
        else
            two++;
    }
    int delta=one-two;
    vector <ll> pref(2*n+1);
    for (int i=0;i<2*n;i++)
    {
        if (a[i]==1)
            pref[i+1]=pref[i]+1;
        else
            pref[i+1]=pref[i]-1;
    }
   // for (int i=0;i<2*n+1;i++)
   //     cout<<pref[i]<<" ";
  //  cout<<'\n';
    vector <set<int> > val(10*n+5);
    int ans=2*n;
    for (int i=n;i<=2*n;i++)
    {
        val[5*n+pref[i]].insert(i);
    }
    for (int j=0;j<n+1;j++)
    {
        ll q=pref[j];
        ll u=delta+pref[j];
        auto p=val[u+5*n].lower_bound(j);
        if (p!=val[u+5*n].end())
            ans=min(ans,*p-j);
    }
    cout<<ans<<'\n';
    }





}
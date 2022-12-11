#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=0;
    int i=0;
    vector <pair <int,int> > o;
    for (int j=0;j<k-1;j++)
    {
       int l=i;
       while (s[l]!='(')
           l++;
       if (l!=i) {
           o.pb({i, l});
           vector <char> c;
           for (int x=i;x<=l;x++)
               c.pb(s[x]);
           reverse(all(c));
           for (int u=0;u<c.size();u++)
               s[i+u]=c[u];
       }
     //  cout<<i<<" "<<l<<'\n';
       l=i+1;
       while (s[l]!=')')
           l++;
        if (l!=i+1) {
            o.pb({i+1, l});
            vector <char> c;
            for (int x=i+1;x<=l;x++)
                c.pb(s[x]);
            reverse(all(c));
            for (int u=0;u<c.size();u++)
                s[i+1+u]=c[u];
        }
        i+=2;
    }
   // cout<<"haha";
    for (int j=0;j<n/2-(k-1);j++)
    {
        int l=i;
        while (s[l]!='(')
            l++;
        if (l!=i) {
            o.pb({i, l});
            vector <char> c;
            for (int x=i;x<=l;x++)
                c.pb(s[x]);
            reverse(all(c));
            for (int u=0;u<c.size();u++)
                s[i+u]=c[u];
        }
        i++;
    }
    cout<<o.size()<<'\n';
    for (int j=0;j<o.size();j++)
        cout<<o[j].first+1<<" "<<o[j].second+1<<'\n';

    }
}
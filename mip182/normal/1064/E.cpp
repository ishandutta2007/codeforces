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

int main() {
  //  ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int n;
    cin>>n;
    cout<<0<<" "<<1<<endl;
    string s;
    cin>>s;
    int f=(s=="white");
    int last=f;
    ll l=0,r=1e9;
    for (int i=1;i<n;i++)
    {
        int mid=(l+r)/2;
        cout<<(l+r)/2<<" "<<1<<endl;
        cin>>s;
        int g=(s=="white");
        if (g==f)
            l=mid;
        else
            r=mid;
    }
    int mid=(l+r)/2;
    cout<<l<<" "<<0<<" "<<r<<" "<<2<<endl;






}
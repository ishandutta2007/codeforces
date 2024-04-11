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
bool comp (pair <int,int> a,pair <int,int> b)
{
    if (a.first!=b.first) return a.first<b.first;
    else
        return a.second>b.second;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
    cin >> a[i];
    vector<pair<ll, ll> > b(n);
    rep(i, n) {
        b[i] = {a[i], i};
    }
    sort(b.begin(),b.end(),comp);
    reverse(b.begin(),b.end());
    int m;
    cin >> m;
    for (int j=0;j<m;j++)
    {
    int k,pos;
    cin>>k>>pos;
    pos--;
    vector <int> c(k);
    for (int i=0;i<k;i++)
        c[i]=b[i].second;
    sort(c.begin(),c.end());
    cout<<a[c[pos]]<<'\n';
    }
}
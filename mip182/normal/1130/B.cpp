#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1000000007;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vi a(2*n);
    rep(i,2*n) {
        cin >> a[i];
        a[i]--;
    }
    vector <int> b(2*n);
    vector <int> c(2*n);
    rep(i,2*n)
    {
        c[a[i]]=i;
    }
    rep(i,2*n)
    {
        if (c[a[i]]!=i)
            b[a[i]]=i;
    }
    int l=0,r=0,curl=0,curr=0;
    ll ans=0;
    while (l<n||r<n)
    {
        if (abs(curr-c[r])+abs(curl-b[l])>=abs(curr-b[r])+abs(curl-c[l]))
        {
            ans+=abs(curr-b[r])+abs(curl-c[l]);
            curr=b[r];
            curl=c[l];

        } else
        {
          ans+=abs(curr-c[r])+abs(curl-b[l]);
          curr=c[r];
          curl=b[l];
        }
        l++,r++;
    }
    cout<<ans;
}
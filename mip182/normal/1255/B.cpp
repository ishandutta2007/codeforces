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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        vector <pair <ll,ll> > a(n);
        rep(i,n)
        cin>>a[i].first;
        if (n==2)
        {
            cout<<-1<<'\n';
            continue;
        }
        rep(i,n)
        a[i].second=i;
        if (m<n)
            cout<<-1<<'\n';
        else
        {   m-=n;
            ll sum=0;
            for (int i=0;i<n;i++)
                sum+=2*a[i].first;
            for (int i=0;i<m;i++)
                sum+=a[0].first+a[1].first;
            cout<<sum<<'\n';
            for (int i=1;i<n;i++)
                cout<<i<<" "<<i+1<<'\n';
            cout<<1<<" "<<n<<'\n';
            sort(a.begin(),a.end());
            for (int i=0;i<m;i++)
                cout<<a[0].second+1<<" "<<a[1].second+1<<'\n';
        }
    }
}
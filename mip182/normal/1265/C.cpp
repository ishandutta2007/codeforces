#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define fi first
#define se second
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


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
        int n;
        cin>>n;
        vector <int> a(n);
        rep(i,n)
            cin >> a[i];
        int u=0,v=0;
        vector <int> c;
        while (u<n)
        {
            int cnt=0;
            while (v<n&&a[u]==a[v])
                cnt++,v++;
            c.pb(cnt);
            u=v;
        }
        ll g=0,s=0,b=0;
        g=c[0];
        int h=1;
        while (h<c.size()&&s<=g)
        {
            s+=c[h];
            h++;
        }
        int j=h;
        while (h<c.size()&&b<=g)
        {
            b+=c[h];
            h++;
        }
      //  cout<<g<<" "<<s<<" "<<b<<" "<<n<<'\n';
        if ((g>=s)||(g>=b)||((g+s+b)>(n)/2)||g==0||b==0||s==0)
            cout<<0<<" "<<0<<" "<<0;
        else
        {
        while (h<c.size()&&(g+s+b+c[h])<=n/2)
        {
            b+=c[h];
            h++;
        }
        cout<<g<<" "<<s<<" "<<b;
        }
        cout<<'\n';


    }}
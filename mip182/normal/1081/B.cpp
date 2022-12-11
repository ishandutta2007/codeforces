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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n;
    cin>>n;
    vector <int> a(n+1,0);
    vector <int> x(n+1);
    for (int i=0;i<n;i++)
    {
        cin>>x[i];
        a[n-x[i]]++;
        x[i]=n-x[i];
    }
    vector <int> ans(n);
    bool ok=true;
    for (int i=1;i<n+1;i++)
    {
     //   cout<<a[i]<<'\n';
        if (a[i]%i!=0)
            ok=false;


    }
    if (!ok)
        cout<<"Impossible";
    else
    {
        cout<<"Possible\n";
        int times=1;
        vector <int> cur(n+1,0);
        vector <int> curr(n+1,-1);
        for (int i=0;i<n;i++)
        {
           // cout<<x[i]<<'\n';
            if (curr[x[i]]==-1)
                curr[x[i]]=times++;
            if ((cur[x[i]]+1)%x[i]==0)
            {
                cout<<curr[x[i]]<<' ';
                curr[x[i]]=-1;
            }
            else
                cout<<curr[x[i]]<<" ";
            cur[x[i]]++;
        }
    }




}
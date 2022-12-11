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
int a[300000+1][9];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    }
    if (n==1)
    {
        cout<<1<<" "<<1;
        return 0;
    }
    ll l=0,r=1e9;
    ll ans=0;
    pair <int,int> answer;
    while (l<=r)
    {
        ll mid=(l+r)/2;
        map <int,int> mm;
        bool ko=false;
        for (int i=0;i<n;i++)
        {
            bool ok=false;
            int x=0;
            for (int j=0;j<m;j++)
            {
                if (a[i][j]>=mid)
                {
                    ok=true;
                    x|=(1<<j);
                }
            }
                x^=((1<<m)-1);
                if (mm[x]>0)
                {
                    answer={mm[x],i+1};
                    ko=true;
                    break;
                }
                else
                {
                    x^=((1<<m)-1);
                    for (int mask=x;mask>0;mask=((mask-1)&x))
                    {
                        mm[mask]=i+1;
                    }
                }
                mm[0]=i+1;
        }
        // cout<<mid<<" "<<ko<<'\n';
        if (ko)
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    cout<<answer.fi<<" "<<answer.se;



}
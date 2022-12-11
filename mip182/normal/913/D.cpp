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
#define for0(i, n) for (int i = 0; i < (n); i++)
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
    ll n,T;
    cin>>n>>T;
    vector <pair <ll,pair <ll,ll> >  > t(n);
    for0(i,n)
    {
        cin>>t[i].second.first>>t[i].first;
        t[i].second.second=i;
    }
    sort(t.begin(),t.end());
    ll l=1,r=n;
    ll ans=0;
    vector <ll> ansv;
    while (l<=r)
    {
        ll mid=((l+r)>>1);
        ll sum=0;
        int cnt=0;
        vector <ll> anss;
        bool ok=true;
        for (int i=0;i<n;i++)
        {
            if (mid<=t[i].second.first)
            {
                sum+=t[i].first;
                anss.pb(t[i].second.second);
                cnt++;
                if (sum>T)
                {
                    ok=false;
                    break;
                }
                if (cnt==mid)
                    break;
            }
        }
        if (cnt==mid&&ok)
        {
            l=mid+1;
            ans=sum;
            ansv=anss;
        } else
            r=mid-1;
    }
    cout<<ansv.size()<<'\n';
    cout<<ansv.size()<<'\n';
    for (int i=0;i<ansv.size();i++)
        cout<<ansv[i]+1<<" ";

}
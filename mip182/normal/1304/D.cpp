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
#define int long long

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
const ll mm=1e6;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector <ll> mxx;
        int curr=0;
        mxx.pb(curr);
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='<')
                curr++;
            else
                curr-=mm;
            mxx.pb(curr);

        }
        map <int,int> mmm;
        vector <ll> aa=mxx;
        sort(all(aa));
        for (int i=0;i<n;i++)
            mmm[aa[i]]=i+1;
        for (int i=0;i<mxx.size();i++)
            cout<<mmm[mxx[i]]<<" ";
        cout<<'\n';
        vector <ll> mx;
        int cur=0;
        mx.pb(cur);
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='<')
                cur+=mm;
            else
                cur--;
            mx.pb(cur);

        }
        map <int,int> m;
        vector <ll> a=mx;
        sort(all(a));
        for (int i=0;i<n;i++)
            m[a[i]]=i+1;
        for (int i=0;i<mx.size();i++)
            cout<<m[mx[i]]<<" ";
        cout<<'\n';

    }




}
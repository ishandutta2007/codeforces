//#define _GLIBCXX_DEBUG
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
const ll mod1=998244353;
const ll mod2=1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        string ss=s;
        reverse(all(ss));
        int cur=0;
        while (cur<n&&s[cur]==ss[cur])
            cur++;
        if (cur==n)
        {
            cout<<s<<'\n';
            continue;
        }
        string anss;
        string anses="";
        for (int i=0;i<cur;i++)
            anses+=s[i];
        string aaa=anses;
        reverse(all(aaa));
     //   cout<<s<<" "<<anses<<" "<<aaa<<'\n';
        string x;
        for (int i=cur;i<n-cur;i++)
            x+=s[i];
        s=x;
        n=s.size();
        vector<int> d1 (n);
        int l=0, r=-1;
        for (int i=0; i<n; ++i) {
            int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
            while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
            d1[i] = k;
            if (i+k-1 > r)
                l = i-k+1,  r = i+k-1;
        }
   //     cout<<s<<'\n';
//        rep(i,n)
//        cout<<d1[i]<<" ";
//        cout<<'\n';
        vector<int> d2 (n);
        l=0, r=-1;
        for (int i=0; i<n; ++i) {
            int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
            while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
            d2[i] = k;
            if (i+k-1 > r)
                l = i-k,  r = i+k-1;
        }
        int ind=-1;
        rep(i,n)
        d1[i]--;
        for (int i=0;i<n;i++)
        {
            if (d1[i]==i)
                ind=i;
        }
        for (int j=0;j<=2*ind;j++)
        {
            anss+=s[j];
        }
        ind =-1;
        for (int j=0;j<n;j++)
        {
            if (j==d2[j])
                ind=j;
        }
        if (ind!=-1&&2*ind>anss.size())
        {
            anss="";
            for (int j=0;j<=2*ind-1;j++)
                anss+=s[j];
        }
        reverse(all(s));
        d1 =vi(n);
        l=0, r=-1;
        for (int i=0; i<n; ++i) {
            int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
            while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
            d1[i] = k;
            if (i+k-1 > r)
                l = i-k+1,  r = i+k-1;
        }
        d2=vi (n);
        l=0, r=-1;
        for (int i=0; i<n; ++i) {
            int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
            while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
            d2[i] = k;
            if (i+k-1 > r)
                l = i-k,  r = i+k-1;
        }
        rep(i,n)
            d1[i]--;
        ind=-1;
        for (int i=0;i<n;i++)
        {
            if (d1[i]==i)
                ind=i;
        }
        if (anss.size()<2*ind+1) {
            anss="";
            for (int j = 0; j <= 2 * ind; j++) {
                anss += s[j];
            }
        }
        ind =-1;
        for (int j=0;j<n;j++)
        {
            if (j==d2[j])
                ind=j;
        }
        if (ind!=-1&&2*ind>anss.size())
        {
            anss="";
            for (int j=0;j<=2*ind-1;j++)
                anss+=s[j];
        }
     //   cout<<s<<" "<<anses<<" "<<anss<<" "<<aaa<<'\n';
        string ansss=anses+anss+aaa;
        cout<<ansss<<'\n';
    }




}
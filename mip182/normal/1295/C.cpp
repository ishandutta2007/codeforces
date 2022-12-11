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
    int T;
    cin>>T;
    while (T--)
    {
       string s,t;
       cin>>s>>t;
       ll n=s.size(),m=t.size();
       vector <vector <int> > prefn(n+1),preft(m+1);
       vector <int> c(26,0);
       prefn[0]=c;
       preft[0]=c;
       for (int i=0;i<n;i++)
       {
           c[s[i]-'a']++;
           prefn[i+1]=c;
       }
       for (int i=0;i<26;i++)
           c[i]=0;
        for (int i=0;i<m;i++)
        {
            c[t[i]-'a']++;
            preft[i+1]=c;
        }

       ll ans=0;
       ll cur=0;
       bool ok=true;
       while (ans<m)
       {
        ll now=0;
        ll wasans=ans;
        vector <int> d(26,0);
        while (now<n&&ans!=m)
        {
            char g=t[ans];
            int l=now+1,r=n;
            int ind=-1;
            while (l<=r)
            {
                int mid=(l+r)/2;
                bool ko=true;
                if (prefn[mid][g-'a']-prefn[now][g-'a']>0)
                    ind=mid,r=mid-1;
                else
                    l=mid+1;
            }
            if (ind==-1)
                break;
            else
                ans++,now=ind,d[g-'a']++;
        }
        cur++;
        if (ans==wasans)
        {
            ok=false;
            break;
        }
       }
       if (ok)
           cout<<cur<<'\n';
       else
           cout<<-1<<'\n';

    }




}
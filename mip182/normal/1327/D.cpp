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
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int p[MAXN];
int c[MAXN];
int check(vector <int> &cyc)
{
    int ans=cyc.size();
    int n=cyc.size();
    for (int i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            vector <int> used(n);
            bool ok=false;
            for (int j=0;j<n;j++)
            {
                if (used[j]==0)
                {
                    int x=j;
                    int was=c[cyc[j]];
                    bool ko=true;
                    while (used[x]==0)
                    {
                        if (c[cyc[x]]!=was)
                        {
                            ko=false;
                        }
                        used[x]=1;
                        x=(x+i)%n;
                    }
                    if (ko)
                    {
                        ok=true;
                        break;
                    }

                }
            }
            if (ok)
                ans=min(ans,i);
            ok=false;
            used=vector <int> (n);
            for (int j=0;j<n;j++)
            {
                if (used[j]==0)
                {
                    int x=j;
                    int was=c[cyc[j]];
                    bool ko=true;
                    while (used[x]==0)
                    {
                        if (c[cyc[x]]!=was)
                        {
                            ko=false;
                        }
                        used[x]=1;
                        x=(x+n/i)%n;
                    }
                    if (ko)
                    {
                        ok=true;
                        break;
                    }

                }
            }
            if (ok)
                ans=min(ans,n/i);
        }
    }
    return ans;
}
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
        int n;
        cin>>n;
        rep(i,n)
        cin>>p[i],p[i]--;
        rep(i,n)
        cin>>c[i];
        vector <int> used(n);
        int ans=INF;
        for (int i=0;i<n;i++)
        {
            if (used[i]==0)
            {
                vector <int> cyc;
                int x=i;
                while (used[x]==0)
                {
                    used[x]=1;
                    cyc.pb(x),x=p[x];
                }
                ans=min(ans,check(cyc));
            }
        }
        cout<<ans<<'\n';
    }




}
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
    map <int,int> m;
    vector <int> a(n);
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=x;
        m[x]++;
    }
    vector <int> b;
    for (auto to:m)
        b.pb(to.second);
    int cnt1=0,cnt0=0,cnt2=0;
    for (int i=0;i<b.size();i++)
    {
     //   cout<<b[i]<<" ";
        if (b[i]==1)
            cnt1++;
        else {
            cnt0++;
            if (b[i]==2)
                cnt2++;
        }
    }
    if (cnt1%2==0)
    {
        cout<<"YES\n";
    for (int i=0;i<n;i++)
    {
        if (m[a[i]]>1)
            cout<<"A";
        else
        {
            if (cnt1%2==0)
                cout<<"B";
            else
                cout<<"A";
            cnt1--;
        }
    }
    } else
    {
        if (cnt0>0&&cnt0!=cnt2)
        {
            cout<<"YES\n";
            bool ok=true;
            for (int i=0;i<n;i++)
            {
                if (m[a[i]]>1)
                {
                  if (ok&&m[a[i]]!=2)
                  {
                      cout<<"B";
                      ok=false;

                  } else
                  {
                    cout<<"A";
                  }
                } else
                {
                    if (cnt1%2==1)
                        cout<<"A";
                    else
                        cout<<"B";
                    cnt1--;
                }
            }

        } else
        {
            cout<<"NO";
        }
    }





}
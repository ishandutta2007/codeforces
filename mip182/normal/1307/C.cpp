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
    string s;
    cin>>s;
 //   cout<<s.size();
    int n=s.size();
    ll mx=1;
    for (int i=0;i<26;i++)
    {
        for (int j=0;j<26;j++)
        {
            ll a=0;
            ll ans=0;
            for (int f=0;f<s.size();f++)
            {
                if (i!=j){
                if (s[f]==(char)('a'+i))
                    a++;
                else
                {
                    if (s[f]==(char)('a'+j))
                        ans+=a;
                } }
                else
                {
                    if (s[f]==(char)('a'+i)) {
                        ans += a;
                        a++;
                    }
                }
            }
            mx=max(ans,mx);
        }
    }
    for (int i=0;i<26;i++)
    {
        ll cnt=0;
        for (int j=0;j<s.size();j++)
        {
            if (s[j]==(char)('a'+i))
                cnt++;
        }
        mx=max(cnt,mx);
    }
    cout<<mx<<'\n';




}
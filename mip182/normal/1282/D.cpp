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
#define rep(i, n) for (int i = 0; i < (n); i++)
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
    //#ifdef LOCAL
    //  freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    //#endif
    for (int i=0;i<300;i++)
    cout<<'a';
    cout<<endl;
    int cnta;
    cin>>cnta;
    if (cnta==0)
        return 0;
    int cntb;
    for (int i=0;i<300;i++)
    cout<<'b';
    cout<<endl;
    cin>>cntb;
    if (cntb==0)
        return 0;
    if (cnta==300)
    {
        for (int i=0;i<300-cntb;i++)
            cout<<'b';
        cout<<endl;
        int x;
        cin>>x;
        return 0;
    }
    if (cntb==300)
    {
        for (int i=0;i<300-cnta;i++)
            cout<<'a';
        cout<<endl;
        int x;
        cin>>x;
        return 0;
    }
    ll n=600-cnta-cntb;
    int x;
    string s="";
    rep(i,n)
    s+='a';
    x=n-300+cnta;
    for (int i=0;i<n;i++)
    {
        s[i]='b';
        cout<<s<<endl;
        int y;
        cin>>y;
        if (y==0)
            return 0;
        if (y>x)
            s[i]='a';
        else
            x=y;
    }
    cout<<s<<endl;
    cin>>x;
    return 0;




}
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
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        int k=1;
        vector <int> a;
        int mx=INF;
        ll pp=n;
        while (pp)
        {
            a.pb(pp%10);
            pp/=10;

        }
        reverse(a.begin(),a.end());
        ll ans=0;
        while (k<a.size())
        {
            ans+=9;
            k++;
        }
        ans+=a[0]-1;
        ll f=a[0];
        ll q=1;
        ll sum=0;
        for (int i=0;i<a.size();i++)
        {
            sum+=f*q;
            q*=10;
        }
        if (sum<=n)
            cout<<ans+1;
        else
            cout<<ans;
        cout<<'\n';

    }






}
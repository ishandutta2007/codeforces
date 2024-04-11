#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define fi first
#define se second
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long>
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        if ((2*b-a)%3==0&&(2*a-b)%3==0&&(2*b-a)/3>=0&&(2*a-b)/3>=0)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
}
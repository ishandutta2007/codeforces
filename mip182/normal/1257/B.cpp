#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll x,y;
        cin>>x>>y;
        if (x==1)
        {
            if  (x>=y)
                cout<<"YES";
            else
                cout<<"NO";
        } else{
        if (x==2||x==3)
        {
            if (3>=y)
                cout<<"YES";
            else
                cout<<"NO";
        } else
        {
            cout<<"YES";
        }
        }
        cout<<'\n';
    }
}
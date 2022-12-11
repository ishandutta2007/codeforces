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
const ll mod1=1000000007;

ll powerf(ll x, ll y)
{
    if (y==0)
        return 1;
    if (y==1)
        return x;
    ll f=(powerf(x,y/2))%mod1;
    if (y%2==1)
        return (((f*f)%mod1)*x)%mod1;
    else
        return (f*f)%mod1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string p;
    cin >> p;
    vector <int> pi(p.size());
    pi[0]=0;
    for (int i=1;i<p.size();i++)
    {
        int j=pi[i-1];
        while (p[i]!=p[j]&&j)
            j=pi[j-1];
        if (p[i]==p[j])
            j++;
        pi[i]=j;
    }
    map <int,int> u;
    int q=pi[p.size()-1];
    while (q)
    {
        u[q]++;
        q=pi[q-1];
    }
    vector <int> y;
    rep(i, m) {
        int x;
        cin >> x;
        y.pb(x);
    }
    if (m==0) {
        cout << powerf((ll) (26), n);
        return 0;
    }
    int cnt = 0;
    cnt += y[0] - 1;
    for (int i = 0; i < m-1; i++)
    {
        if ((y[i]+(int)(p.size())-1)>=y[i+1])
        {
            if (u[y[i]+(int)(p.size())-y[i+1]]==0){
           // cout<<y[i]+(int)p.size()-y[i+1]<<" "<<i<<endl;
            cout<<0;
            return 0;}}
         else
            cnt+=y[i+1]-(y[i]+(int)(p.size()));
    }
    cnt+=n-(y[m-1]+(int)(p.size()))+1;
    cout<<powerf(ll(26),cnt);
}
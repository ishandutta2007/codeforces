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
const int MAXN = 3e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1000000007;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vi a(n);
    rep(i,n)
    cin>>a[i];
    int cnt=0;
    int chet=0;
    rep(i,n)
    {
        if (a[i]>0)
            cnt++;
        if (a[i]<0)
            chet++;
    }
    if (cnt>=((n+1)/2))
        cout<<1;
    else
    {
        if (chet>=((n+1)/2))
            cout<<-1;
        else
            cout<<0;
    }
}
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <string>
#include <random>
typedef long long ll;
#define pb push_back
#define pf push_front
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define sz(x) (int)x.size()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,h;
    cin>>n>>m>>h;
    vll a(m),b(n);
    rep(i,m)
    cin>>a[i];
    rep(i,n)
    cin>>b[i];
    int t[n][m];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cin>>t[i][j];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (t[i][j])
                t[i][j]=min(b[i],a[j]);
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}
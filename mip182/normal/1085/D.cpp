#include <bits/stdc++.h>
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
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define sz(x) (int)x.size()

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;
vector <vector <int> > g;

int main() {
mipletsplay;
int n;
cin>>n;
g=vector < vi > (n);
double s;
cin>>s;
for (int i=0;i<n-1;i++)
{
int a,b;
cin>>a>>b;
a--,b--;
g[a].pb(b);
g[b].pb(a);
}
double cnt=0;
rep(i,n)
{
    if (g[i].size()==1)
    cnt++;
}
double ans=2*s/cnt;
cout<<setprecision(20)<<ans;}
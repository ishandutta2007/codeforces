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
ll mas[20][20];
int x,y;
void func(ll a, ll b,ll cur, map <ll,ll> &m)
{
if (x==a&&y==b)
m[cur]++;
else{
cur^=mas[a][b];
if (a<x)
func(a+1,b,cur,m);
if (b<y)
func(a,b+1,cur,m);
}
}


int main() {
mipletsplay;
ll n,m,k;
cin>>n>>m>>k;
rep(i,n)
{
rep(j,m)
cin>>mas[i][j];
}
ll ans=0;
for (int i=0;i<m;i++)
{
y=i;
x=n-1-i;
mll m1;
func(0,0,0,m1);
x=n-1;
y=m-1;
mll m2;
ll t=mas[n-1][m-1];
func(n-1-i,i,t,m2);

for (auto to:m1)
{
ans+=to.second*m2[to.first^k];
}
}
cout<<ans;}
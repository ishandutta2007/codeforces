#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,sse4,O3")
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
 
int main() {
mipletsplay;
ll n,k;
cin>>n>>k;
vector <ll> m(1e5+1,0);
vector <int> a(n);
rep(i,n)
{
ll x;
cin>>x;
a[i]=x;
m[x]++;
}
ll ans=0;
//cout<<pow((double)(1e10),(double)(1)/(double)(k))<<endl;
if (k!=2){
for (ll i=1;i<=pow((double)(1e10),(double)(1)/(double)(k));i++)
{
ll f=pow(i,k);
for (ll j=1;j*j<=f;j++) 
{
if (f%j==0){
if (j<=1e5&&f/j<=1e5)
{
if (j*j!=f)
ans+=m[j]*m[f/j];
else
ans+=(m[j]*(m[j]-1))/2;
}
}
}
    
    
}
cout<<ans;}
else
{
map <vector <int>,ll> u;
ll ans=0;
rep(i,n)
{
vi c;
int y=a[i];
for (int j=2;j*j<=y;j++)
{
if (y%j==0)
{
int cnt=0;
while (y%j==0)
{
y/=j;
cnt++;
}
if (cnt%2==1)
c.pb(j);
}
}
if (y>1)
c.pb(y);
if (c.size()==0)
ans++;
else
{
sort(c.begin(),c.end());
u[c]++;}
}
ll answer=ans*(ans-1)/2;
for (auto to:u)
{
answer+=to.second*(to.second-1)/2;
}
cout<<answer;
 
    
}}
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
ll n,p;
cin>>n>>p;
for (ll i=1;i<=10000000;i++)
{
ll m=n;
m-=i*p;
ll f=m;
if (m<=0)
break;
vector <int> a;
while (m)
{
a.pb(m%2);
m/=2;
}
vector <int> c;
for (int j=0;j<a.size();j++)
{
if (a[j]==1)
c.pb(j);
}
if (i>=c.size()&&f>=i)
{
cout<<i;
return 0;
}
}
cout<<-1;}
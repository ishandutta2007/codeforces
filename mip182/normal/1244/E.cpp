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


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
ll n,k;
cin>>n>>k;
vector <ll> a(n);
rep(i,n)
cin>>a[i];
sort(all(a));
map <ll,int> m;
for (int i=0;i<n;i++)
m[a[i]]++;
vector <ll> b;
int w=0,e=0;
while (w<n)
{
while (e<n&&a[w]==a[e])
e++;
b.pb(a[w]);
w=e;
}
ll l=a[0],r=a[n-1];
a=b;
int c=0,d=b.size()-1;
while (true)
{
if (r-l==0)
{
cout<<0;
return 0;
}
if (m[l]<=m[r])
{
if (k>=(a[c+1]-l)*m[l])
{
k-=(a[c+1]-l)*m[l];
m[a[c+1]]+=m[l];
l=a[c+1];
c++;
}
else
{
ll h=k/m[l];
l+=h;
cout<<r-l;
return 0;
}
}
else
{
if (k>=(r-a[d-1])*m[r])
{
k-=(r-a[d-1])*m[r];
m[a[d-1]]+=m[r];
r=a[d-1];
d--;
}
else
{
ll h=k/m[r];
r-=h;
cout<<r-l;
return 0;
}
}
}}
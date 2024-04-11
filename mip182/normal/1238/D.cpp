#include <bits/stdc++.h>
typedef long long ll;
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j)
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


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;


int main() {
mipletsplay;
ll n;
cin>>n;
string s;
cin>>s;
ll ans=((n-1)*n)/2;
vector <ll> a;
int l=0,r=0;
while (l<n)
{
int cnt=0;
while (r<n&&s[l]==s[r])
{
cnt++;
r++;
}
a.pb(cnt);
l=r;
}
for (int i=0;i<a.size()-1;i++)
{
if (a[i]>1||a[i+1]>1)
ans-=a[i]+a[i+1]-1;
else
ans-=max(a[i],a[i+1]);
}
cout<<ans;}
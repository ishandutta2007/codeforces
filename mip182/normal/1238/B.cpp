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
int q;
cin>>q;
rep(jj,q)
{
ll n,r;
cin>>n>>r;
vll x(n);
for (int i=0;i<n;i++)
cin>>x[i];
sort(x.begin(),x.end());
vector <ll> y;
int l=0,d=0;
while (l<n)
{
while (x[l]==x[d]&&d<n)
d++;
y.pb(x[l]);
l=d;
}
x=y;
ll ans=0;
ll cnt=0;
ll j=x.size()-1;
while (j>=0&& (x[j]-cnt*r)>0)
{
ans++;
j--;
cnt++;
}
cout<<ans<<endl;
    
    
}}
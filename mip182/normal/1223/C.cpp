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
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const ll MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
int q;
cin>>q;
for (int j=0;j<q;j++)
{
ll n;
cin>>n;
vector <ll> p(n);
for (int i=0;i<n;i++)
cin>>p[i];
sort(p.begin(),p.end());
reverse(p.begin(),p.end());
vector <ll> pref(n+1);
pref[0]=0;
for (int i=0;i<n;i++)
pref[i+1]=pref[i]+p[i];
ll x,a;
cin>>x>>a;
ll y,b;
cin>>y>>b;
ll k;
cin>>k;
if (x>=y)
{
ll l=0,r=n;
ll ans=-1;
while (l<=r)
{
ll mid=l+(r-l)/2;
ll o=(a*b)/(__gcd(a,b));
ll sum=(pref[mid/a]*x)/100+(pref[mid/o]*y)/100+((pref[mid/a+mid/b-mid/o]-pref[mid/a])*y)/100;
if (sum>=k)
{
r=mid-1;
ans=mid;
}
else
l=mid+1;
}
cout<<ans<<endl;
}
else
{
ll l=0,r=n;
ll ans=-1;
while (l<=r)
{
ll mid=(l+r)/2;
ll o=(a*b)/(__gcd(a,b));
ll sum=(pref[mid/b]*y)/100+(pref[mid/o]*x)/100+((pref[mid/a+mid/b-mid/o]-pref[mid/b])*x)/100;
//cout<<sum<<endl;
if (sum>=k)
{
r=mid-1;
ans=mid;
}
else
l=mid+1;
}
cout<<ans<<endl;    
    
    
    
    
}


    
    
    
    
}}
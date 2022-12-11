#include <bits/stdc++.h>
typedef long long ll;
#define vstroku() to_string()
#define vchislo() to_ulong()
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back 
#define F first
#define S second
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 
 
 
using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;
 
int main() {
mipletsplay;
 
int n;
cin>>n;
ll k;
cin>>k;
ll f=1;
vector <ll> kk;
while (f<1e15 && abs(k)!=1)
{
kk.pb(f);
f*=k;
}
if (abs(k)==1){
kk.pb(1);
if (k==-1)
kk.pb(-1);
}
vector <ll> pref(n+1);
pref[0]=0;
map <ll, ll > my;
for (int i=0;i<n;i++)
{
ll x;
cin>>x;
pref[i+1]=pref[i]+x;
//for (int j=0;j<kk.size();j++)
//my[pref[i+1]-kk[j]]++;
}
ll sum=0;
for (int i=n;i>0;i--){
for (int j=0;j<kk.size();j++)
my[pref[i]-kk[j]]++;
sum+=my[pref[i-1]];
}
cout<<sum;}
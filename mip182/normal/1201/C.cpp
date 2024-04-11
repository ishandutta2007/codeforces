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

int n,k;
cin>>n>>k;
vector <ll> a(n);
for (int i=0;i<n;i++)
cin>>a[i];
sort(a.begin(),a.end());
vector <ll> razn(n/2);
for (int i=n/2;i<n-1;i++)
{
razn[i-n/2]=a[i+1]-a[i];    
}
ll ans=a[n/2];
ll chet=1,j=0;
while (j<n/2 && k>=razn[j]*chet)
{
k-=razn[j]*chet;
ans+=razn[j];
chet++;
j++;
}
ans+=k/chet;
cout<<ans;}
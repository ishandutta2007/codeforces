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
 
ll n,I;
cin>>n>>I;
map <int,int>m;
for (int i=0;i<n;i++)
{
 ll x;
 cin>>x;
 m[x]++;
}
vector <int> a;

for (auto it:m)
a.pb(it.second);
ll ans=(I*8)/n;
if (ans>=31)
cout<<0;
else
{
ans=pow(2,ans);
ll i=0,j=0,answer=INF,summa=0,chet=0;
while (i<a.size())
{
while(j<a.size() && chet<ans)
{
 summa+=a[j];
 chet++;
 j++;
 
}
answer=min(answer,n-summa);
summa-=a[i];
chet--;
i++;
}
cout<<answer;
 
 
 
}
}
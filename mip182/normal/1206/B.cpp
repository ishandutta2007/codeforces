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
vector <ll> a(n);
ll cnt=0,chet=0,y=0;
for (int i=0;i<n;i++){
cin>>a[i];
if (a[i]>0)
cnt+=a[i]-1;
else
{
if (a[i]<0){
cnt+=-a[i]-1;
chet++;
}
else
y++;
}
}
if (chet%2==0)
cout<<cnt+y;
else
{
 if (y>0)
 cout<<cnt+y;
 else
 cout<<cnt+2;
    
    
}}
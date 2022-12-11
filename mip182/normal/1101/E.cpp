#include <bits/stdc++.h>
typedef long long ll;
#define vstroku() to_string()
#define vchislo() to_ulong()
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
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
 
int main(){
mipletsplay;
int n;
cin>>n;
int a=-1,b=-1;
for (int i=0;i<n;i++)
{
 char s;
 cin>>s;
 if (s=='+'){
 int x,y;
 cin>>x>>y;
 a=max(a,max(x,y));
 b=max(b,min(x,y));
 }
 else
 {
 int h,w;
 cin>>h>>w;
 if (max(h,w)>=a && min(h,w)>=b)
 cout<<"YES"<<'\n';
 else
 cout<<"NO"<<'\n';
     
     
 }
 }
}
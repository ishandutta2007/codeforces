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
#define pii pair <int, int>
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

int t;
cin>>t;
for (int jj=0;jj<t;jj++)
{
 int b,p,f;
 cin>>b>>p>>f;
 int h,c;
 cin>>h>>c;
 int ans=0;
 if (h>=c)
 {
 ans+=h*min(p,b/2);
 b-=min(p,b/2)*2;
 ans+=min(b/2,f)*c;
 }
 else
 {
 ans+=min(b/2,f)*c;
 b-=min(f,b/2)*2;
 ans+=h*min(p,b/2);
 }  
 cout<<ans<<endl;
    
    
}}
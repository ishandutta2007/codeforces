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
ll trol(ll m)
{
return m*m-m;
}
ll trolling(ll m)
{
return (m*m-m)/2;
}
int main() {
mipletsplay;

int t;
cin>>t;
for (int i=0;i<t;i++)
{
 ll n;
 cin>>n;
 vector <ll> anses;
 if (n%2==0){
 cout<<"11";
 while (n>0){
 ll l=0,r=1e6,ans;
 while (l<=r)
 {
 ll mid=l +(r-l)/2;
 if (trol(mid)<=n)
      {
          ans=mid;
          l=mid+1;
      }
      else
      r=mid-1;
   
 }
 n-=trol(ans);
 anses.pb(ans);
 }
 anses.pb(0);
 for (ll i=anses.size()-2;i>=0;i--)
 {
 for (ll j=0;j<anses[i]-anses[i+1];j++)    
 cout<<"3";
 cout<<"7";
     
     
 }
 cout<<endl;
 }
 else {
 cout<<"1";
 while (n>0){
 ll l=0,r=1e7,ans;
 while (l<=r)
 {
 ll mid=l +(r-l)/2;
 if (trolling(mid)<=n)
      {
          ans=mid;
          l=mid+1;
      }
      else
      r=mid-1;
   
 }
 n-=trolling(ans);
 anses.pb(ans);
 }
 anses.pb(0);
 for (ll i=anses.size()-2;i>=0;i--)
 {
 for (ll j=0;j<anses[i]-anses[i+1];j++)    
 cout<<"3";
 cout<<"7";
     
     
 }
 cout<<endl;
 
 
 
 
 
 
 
 
 }
 
    
    
    
}}
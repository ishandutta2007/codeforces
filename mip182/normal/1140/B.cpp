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
int t;
cin>>t;
for (int i=0;i<t;i++)
{
 int n;
 cin>>n;
 string s;
 cin>>s;
 ll ans1=0,ans2=0;
 for (int j=0;j<n;j++)
 {
 if (s[j]!='>')    
 ans1++;
 else
 break;
     
 }
 for (int j=n-1;j>=0;j--)
 {
 if (s[j]!='<')    
 ans2++;
 else
 break;
     
 }
 cout<<min(ans1,ans2)<<"\n";  
    
    
}
}
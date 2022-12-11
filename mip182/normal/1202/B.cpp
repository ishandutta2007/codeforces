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
 
string s;
cin>>s;
int a[10][10];
int dose[10][10][10][10];
for (int i=0;i<10;i++)
{
for (int j=0;j<10;j++)
{
for (int cnt=0;cnt<10;cnt++)
{
    
for (int h=0;h<10;h++){
int sos=INF;
for (int f=0;f<11;f++)
{
for (int r=0;r<11;r++)
{
if ((cnt+i*f + r*j-h)%10==0){
if (r>0 || f>0)
sos=min(sos,r+f);
}
}
    
}
if (sos==INF)
dose [i][j][cnt][h]=-1;
else
dose [i][j][cnt][h]=sos-1;
}    
    
    
}  
    
    
}
}
for (int i=0;i<10;i++)
{
for (int j=0;j<10;j++)
{
a[i][j]=0;
int cnt=0;
for (int x=1;x<s.size();x++)
{
int h=s[x]-'0';
if (dose[i][j][cnt][h]==-1){
a[i][j]=-1;
break;}
else
a[i][j]+=dose[i][j][cnt][h];
cnt=h;
    
    
}
}    
}
for (int i=0;i<10;i++)
{
for (int j=0;j<10;j++)
cout<<a[i][j]<<" ";
cout<<endl;    
    
    
    
}
    
    
    
}
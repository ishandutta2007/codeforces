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
int b[2000][2000];
for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
    b[i][j]=0;
}
vector <string> a(n);
vector < int > strokl(n,n), strokr(n,-1), cold(n,-1), colu(n,n);

for (int i=0;i<n;i++)
cin>>a[i];
for (int i=0;i<n;i++)
{
for (int j=0;j<n;j++)
{
if (a[i][j]=='B')
{
strokl[i]=min(strokl[i],j);
strokr[i]=max(strokr[i],j);
colu[j]=min(colu[j],i);
cold[j]=max(cold[j],i);
}
}
}
/* for (int i=0;i<n;i++)
cout<<strokl[i]<<" "<< strokr[i]<<endl; */
int sum=0;
for (int i=0;i<n;i++)
{
if (strokr[i]==-1)
sum++;
else{
if (strokr[i]-strokl[i]<=k-1) 
{
for (int j=max(0,strokr[i]-k+1);j<=strokl[i];j++)
//b[i][j]++;
{
for (int h=max(i-k+1,0);h<=i;h++)
b[h][j]++;
    
}    
}
}
if (cold[i]==-1)
sum++;
else
{
if (cold[i]-colu[i]<=k-1)    
{
for (int j=max(0,cold[i]-k+1);j<=colu[i];j++)
//b[j][i]++;   
{
for (int h=max(i-k+1,0);h<=i;h++)
b[j][h]++;
    
}
}    
}
}
int maxi=-1;
/* cout<<sum<<endl;
for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
    cout<<b[i][j]<<endl;
} */ 
for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
    maxi=max(maxi,b[i][j]);
}
cout<<maxi+sum;
}
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

int n,m;
cin>>n>>m;
ll a[100][100];
ll b[100][100];
for (int i=0;i<n;i++)
{
for (int j=0;j<m;j++)
{
int x;
cin>>x;
a[i][j]=x;
b[i][j]=0;
}
}
vector <pair <int,int> > ans;
int k=0;
bool ok=true;
for (int j=0;j<m;j++)
{
    for (int i=0;i<n;i++)
    {
    if (a[i][j]!=b[i][j])
    {
    if (a[i][j]==1&&a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1)
    {
    k++;
    ans.pb({i+1,j+1});
    b[i][j]=1;b[i+1][j]=1;b[i][j+1]=1;b[i+1][j+1]=1;
    }
    else
    {
    if (a[i-1][j-1]==1&&a[i][j]==1&&a[i][j-1]==1&&a[i-1][j]==1)
    {
     k++;
    ans.pb({i,j});
    b[i-1][j-1]=1;b[i][j]=1;b[i][j-1]=1;b[i-1][j]=1;
    }
    else
    {
    if (a[i-1][j]==1&&a[i][j]==1&&a[i-1][j+1]==1&&a[i][j+1]==1)
    {
     k++;
    ans.pb({i,j+1});   
    b[i-1][j]=1;b[i][j]=1;b[i-1][j+1]=1;b[i][j+1]=1;
    }
    else
    {
     if (a[i][j-1]==1&&a[i][j]==1&&a[i+1][j-1]==1&&a[i+1][j]==1)
     {
      k++;
    ans.pb({i+1,j});    
    b[i][j-1]=1;b[i][j]=1;b[i+1][j-1]=1;b[i+1][j]=1;
     }
     else
     ok=false;
    }
        
    }
        
    }
        
        
        
    }
        
        
        
        
        
    }
}
if (ok==false)
cout<<-1;
else
{
    cout<<k<<endl;
    for (int i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
}}
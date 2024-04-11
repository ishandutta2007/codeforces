#include <bits/stdc++.h>
typedef long long ll;
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back 
#define pii pair <int, int>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=1e9+7;

int main() {
mipletsplay;
int n,m;
cin>>n>>m;
int a[n][m];
for (int i=0;i<n;i++)
{
for (int j=0;j<m;j++)
cin>>a[i][j];
}
ll sum=0;
bool ok=true;
for (int i=m-1;i>=0;i--)
{
for (int j=n-1;j>=0;j--)
{
if (a[j][i]==0){
int q=min(a[j+1][i],a[j][i+1])-1;
if (q>0 && a[j-1][i]<q&&a[j][i-1]<q){
a[j][i]=q;
}
else
ok=false;
}
sum+=a[j][i];
}
}
for (int i=m-1;i>=0;i--)
{
for (int j=n-1;j>=0;j--)
{
if ((j<n-1&&a[j][i]>=a[j+1][i])||(a[j][i]>=a[j][i+1]&&i<m-1)||(a[j][i]<=a[j-1][i]&&j>0)||(a[j][i]<=a[j][i-1]&&i>0))
ok=false;
}
}
if (ok)
cout<<sum;
else
cout<<-1; }
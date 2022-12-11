#include <bits/stdc++.h>
typedef long long ll;
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define vi vector <int>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll mod=1e9+7;

int main() {
mipletsplay;

int h,w;
cin>>h>>w;
vector <ll> r(h),c(w);
for (int i=0;i<h;i++)
cin>>r[i];
for (int i=0;i<w;i++)
cin>>c[i];
ll a[h][w];
for (int i=0;i<h;i++)
{
for (int j=0;j<w;j++)
a[i][j]=-1;
}
bool ok=true;
for (int i=0;i<h;i++)
{
for (int j=0;j<r[i];j++){
if (a[i][j]==-1||a[i][j]==1)
a[i][j]=1;
else
ok=false;
}
if (r[i]<w)
{
if (a[i][r[i]]==-1||a[i][r[i]]==0)
a[i][r[i]]=0;
else
ok=false;
}
}
for (int i=0;i<w;i++)
{
for (int j=0;j<c[i];j++)
{
if (a[j][i]==-1||a[j][i]==1)
a[j][i]=1;
else
ok=false;
}
if (c[i]<h)
{
if (a[c[i]][i]==-1||a[c[i]][i]==0)
a[c[i]][i]=0;
else
ok=false;
}
}
ll ans=0;
for (int i=0;i<h;i++)
{
for (int j=0;j<w;j++)
{
if (a[i][j]==-1)
ans++;
}
}
if (ok)
{
ll sum=1;
while (ans)
{
sum*=2;
sum%=mod;
ans--;
}
cout<<sum;
}
else
cout<<0;}
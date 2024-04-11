// I coding this on mobil3
#include<bits/stdc++.h>
using namespace std;
#define mn 200005
#define int long long
#define inf 4444444444444444444
int k1, k2, k3;
int P[3][mn];
int fret[mn][3];

int f(int i, int u)
{
if (fret[i][u]!=-1) return fret[i][u];
if (i==0 && u==0) return 0;
int ret=inf;
if (i>0) ret=f(i-1, u)+(1-P[u][i]);
if (u>0) ret=min(ret, f(i, u-1));
return fret[i][u]=ret;
}

signed main()
{
for (int i=0; i<mn; i++) fret[i][1]=fret[i][2]=fret[i][0]=-1;
cin>>k1>>k2>>k3;
int n=k1+k2+k3;
int u;
while (k1--)
{
cin>>u;
P[0][u]=1;
}
while (k2--)
{
cin>>u;
P[1][u]=1;
}
while (k3--)
{
cin>>u;
P[2][u]=1;
}
cout<<f(n, 2);
}
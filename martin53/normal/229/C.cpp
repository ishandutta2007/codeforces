#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,m;
int SZ[nmax];
int main()
{
cin>>n>>m;
int x,y;
for(int i=1;i<=m;i++)
{
    scanf("%i%i",&x,&y);
    SZ[x]++;
    SZ[y]++;
}
long long ans=1LL*n*(n-1)*(n-2)/6;
long long red=0;
for(int i=1;i<=n;i++)
    red=red+1LL*SZ[i]*(n-1-SZ[i]);
//cout<<ans<<" "<<red<<endl;
cout<<ans-red/2<<endl;
return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+20;
int n,m;
char inp[nmax][nmax];
int main()
{
cin>>n>>m;
int s=0;
int i1=0,j1,i2,j2;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
    cin>>inp[i][j];
    if(inp[i][j]=='B'&&i1==0)i1=i,j1=j;
    if(inp[i][j]=='B')i2=i,j2=j;
    }
cout<<(i1+i2)/2<<" "<<(j1+j2)/2<<endl;
return 0;
}
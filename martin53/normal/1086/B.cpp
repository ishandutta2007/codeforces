#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
int s;
int SZ[nmax];
void print(double x)
{
    printf("%.12f\n",x);
    exit(0);
}
int main()
{
cin>>n>>s;
int x,y;
for(int i=1;i<n;i++)
{
    cin>>x>>y;
    SZ[x]++;
    SZ[y]++;
}
int l=0;
for(int i=1;i<=n;i++)
    if(SZ[i]==1)l++;

print(1.0*s/l*2);
return 0;
}
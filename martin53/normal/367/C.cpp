#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
int w[nmax];
bool bad(long long value)
{
long long need=value*(value-1)/2+1;
if(value%2==0)need=need+value/2-1;
return need>n;
}
int main()
{
cin>>n>>m;
for(int i=1;i<=m;i++)
{
cin>>w[i]>>w[i];
}
sort(w+1,w+m+1);

int t=m;
while(bad(t))t--;

long long ans=0;
for(int j=m;j>m-t;j--)
    ans=ans+w[j];
cout<<ans<<endl;
return 0;
}
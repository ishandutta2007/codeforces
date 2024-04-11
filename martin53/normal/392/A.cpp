#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main()
{
cin>>n;
if(n==0)
{
    cout<<1<<endl;
    return 0;
}
long long j=n;
for(long long i=0;i<=n;i++)
{
    while(i*i+j*j>n*n)j--;
    long long j_=j;
    while((i+1)*(i+1)+j_*j_>n*n&&j_)j_--,ans++;
    if(j==j_)ans++;
    //cout<<i<<" "<<j<<" "<<j_<<endl;
}
ans=(ans-1)*4;
cout<<ans<<endl;
return 0;
}
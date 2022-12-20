#include<bits/stdc++.h>
using namespace std;
const int lim=3e8+42;
bitset<lim> prime;//0->prime
int main()
{
int l,r;
cin>>l>>r;
int ans=0;
if(l<=2&&2<=r)ans++;
int p=3;
prime[0]=1;
prime[1]=1;
while(p*p<lim)
{
    int add=2*p;
    for(int j=p*p;j<lim;j=j+add)prime[j]=1;
    p=p+2;
    while(prime[p])p=p+2;
}
int x=l;
while(x%4!=1)x++;
for(;x<=r;x=x+4)
    if(prime[x]==0)ans++;
cout<<ans<<endl;
return 0;
}
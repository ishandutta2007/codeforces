#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
cin>>n>>m;
int x,g=0;
for(int i=1;i<=n;i++)
{
    cin>>x;
    g=__gcd(g,x-1);
}

while(g%2==0)g=g/2;

set<int> divs={};
for(int i=1;i*i<=g;i++)
    if(g%i==0)
    {
    divs.insert(i);
    divs.insert(g/i);
    }

long long ans=0;
for(auto d:divs)
{
    int num=d;
    while(num<m)
    {
        ans=ans+(m-num);
        num=num*2;
    }
}
cout<<ans<<endl;
return 0;
}
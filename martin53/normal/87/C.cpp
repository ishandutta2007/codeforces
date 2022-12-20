#include<bits/stdc++.h>
using namespace std;
const int lim=1e5+5;
int sg[lim];
int main()
{
sg[0]=0;
for(int i=1;i<lim;i++)
{
    int l=(1+sqrt(8*i+9))/2+5;
    vector<int> seen(l,0);
    for(int k=2;k*(k-1)/2<=i;k++)
    {
        int v=i-k*(k-1)/2;
        if(v%k!=0||v==0)continue;
        int ak=v/k;
        int x=0;
        for(int add=0;add<k;add++)
            x=x^sg[add+ak];
        if(x<l)seen[x]=1;
    }
    int p=0;
    while(seen[p])p++;
    sg[i]=p;
    //cout<<i<<" -> "<<p<<endl;
}
int n;
cin>>n;
if(sg[n]==0)
{
cout<<-1<<endl;
return 0;
}

    for(int k=2;k*(k-1)/2<=n;k++)
    {
        int v=n-k*(k-1)/2;
        if(v%k!=0||v==0)continue;
        int ak=v/k;
        int x=0;
        for(int add=0;add<k;add++)
            x=x^sg[add+ak];
        if(x==0)
        {
        cout<<k<<endl;
        return 0;
        }
    }
assert(0==1);
return 0;
}
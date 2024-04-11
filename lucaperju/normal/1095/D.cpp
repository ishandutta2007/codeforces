#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
vector<int> v[200005];
int rez[200005];
int main()
{
    long long t,n,i,j=0,k,s=0,st,cnt=0,pz=1,pr,idk=0,ina,inb;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a,b;
        cin>>a>>b;
        if(i==1)
            ina=a,inb=b;
        v[b].push_back(a);
        v[a].push_back(b);
    }
    rez[++idk]=1;
    pz=v[1][1];
    pr=1;
    while(pz!=1)
    {
        rez[++idk]=pz;
        if(pr==v[pz][0])
        {
            pr=pz;
            pz=v[pz][1];
        }
        else
        {
            pr=pz;
            pz=v[pz][0];
        }
    }
    if(rez[2]==ina && rez[3]==inb || rez[2]==inb && rez[3]==ina)
        for(i=1;i<=n;++i)
            cout<<rez[i]<<' ';
    else
        for(i=n;i>=1;--i)
            cout<<rez[i]<<' ';
}
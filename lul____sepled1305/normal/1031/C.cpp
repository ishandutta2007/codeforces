#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,l,n,m,o,p,kk,counti;
long long int a[800000];
int main()
{
    cin>>n>>m;
    for(i=1;i<1e6;i++)
    {
        l+=i;
        if(l>n+m)
        {
            l-=i; i--;
            break;
        }
    }
    o=i;
    for(k=1;k<=i;k++)
    {
        a[k]++;
    }
    kk=n;
    while(kk>0)
    {
        if(kk>=o)
        {
            counti++;
            kk-=o;
        }
        o--;
        if(o<=0)
        {
            break;
        }
    }
    cout<<counti<<"\n";
    o=i; if(i==0) o=1;
    while(n>0 || o==0)
    {
        if(n>=o)
        {
            printf("%d ",o);
            a[o]--;
            n-=o;
        }
        o--;
        if(o<=0)
        {
            break;
        }
    }
    cout<<"\n";
    cout<<i-counti<<"\n";
    for(p=1;p<=i;p++)
    {
        if(a[p]>0)
        {
            printf("%d ",p);
        }
    }
    return 0;
}
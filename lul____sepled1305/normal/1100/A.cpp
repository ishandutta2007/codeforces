#include<bits/stdc++.h>
using namespace std;
int n,k,i,l,e,s,j,maxi,g;
int a[1000];
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(j=0;j<=n;j++)
    {
        e=0;
        s=0;
        for(l=1;l<=n;l++)
        {
            if(a[l]==1 && l%k!=j%k)
            {
                e++;
            }
            else if(l%k!=j%k)
            {
                s++;
            }
        }
        //cout<<e<<s<<" ";

        if(e>s) e=e-s; else e=s-e;
        if(e>=maxi) {maxi=e; g=j;}
    }
    cout<<maxi;
    return 0;
}
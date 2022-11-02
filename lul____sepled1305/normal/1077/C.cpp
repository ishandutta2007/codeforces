#include<bits/stdc++.h>
using namespace std;
long long int n,i,f,j=0,sum=0,dis,maxi=0,s,h;
int main(){
    cin>>n;
    long long a[n+1];
    long long b[n+1];
    long long c[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=0;
        c[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(maxi<a[i])
        {
            maxi=a[i];
        }
    }
    for(i=1;i<=n;i++)
    {
        if(a[i] != maxi)
        {
            sum+=a[i];
        }
        else if(a[i] == maxi &&j!=0)
        {
            sum+=a[i];
        }
        else
        {
            j++;
        }
    }
    dis=sum-maxi;
    for(i=1;i<=n;i++)
    {
        if(a[i]==dis && a[i]!=maxi)
        {
            b[i]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]==maxi)
        {
            c[i]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]==maxi)
        {
            a[i]=0;
            break;
        }
    }
    maxi=0;
    j=0;
    for(i=1;i<=n;i++)
    {
        if(maxi<a[i])
        {
            maxi=a[i];
        }
    }
    sum=0;
    for(i=1;i<=n;i++)
    {
        if(a[i] != maxi)
        {
            sum+=a[i];
        }
        else if(a[i] == maxi &&j!=0)
        {
            sum+=a[i];
        }
        else
        {
            j++;
        }
    }
    dis=maxi-sum;
    if(dis==0)
    {
        for(i=1;i<=n;i++)
        {
            if(c[i]==1)
            {
                b[i]=1;
            }
        }
    }
    f=0;
    for(i=1;i<=n;i++)
    {
        if(b[i]>0)
        {
            f++;
        }
    }
    cout<<f<<"\n";
    for(i=1;i<=n;i++)
    {
        if(b[i]>0)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
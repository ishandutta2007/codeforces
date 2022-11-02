#include<bits/stdc++.h>
using namespace std;
long long i,n,m,mini=1e9,index;
long long f[100010];
int main()
{
    cin>>n;
    if(n%2==0)
    {
        for(i=1;i<=n;i++)
        {
            cin>>m;
            if(m>=0)
            {
                cout<<-m-1<<" ";
            }
            else
            {
                cout<<m<<" ";
            }
        }
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            cin>>f[i];
            if(f[i]>=0)
            {
                f[i]=-f[i]-1;
            }
            if(mini>f[i])
            {
                mini=f[i];
                index=i;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(i!=index)
            {
                cout<<f[i]<<" ";
            }
            else
            {
                cout<<-f[i]-1<<" ";
            }
        }
    }
    return 0;
}
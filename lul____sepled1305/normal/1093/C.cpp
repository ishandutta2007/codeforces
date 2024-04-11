#include<bits/stdc++.h>
using namespace std;
long long int n,i,l,o,p;
long long int a[100005];
long long int b[200010];
int main()
{
    cin>>n;
    b[0]=0;
    b[n+1]=2e18+7;
    for(i=1;i<=n/2;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n/2;i++)
    {
        if(b[i-1]<a[i]-b[n-i+2])
        {
            b[n-i+1]=b[n-i+2];
            b[i]=a[i]-b[n-i+1];
            /*b[i]=b[i-1];
            b[n-i]=a[i]-b[i];*/
        }
        else
        {
            b[i]=b[i-1];
            b[n-i+1]=a[i]-b[i];
            /*b[n-i]=b[n-i+1];
            b[i]=a[i]-b[n-i];*/
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
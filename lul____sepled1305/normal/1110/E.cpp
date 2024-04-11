#include<bits/stdc++.h>
using namespace std;
int n,i,j,check;
int a[500000];
int c[500000],d[500000];
int b[500000];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        c[i-1]=a[i]-a[i-1];
    }
    c[n]=a[n];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        d[i-1]=b[i]-b[i-1];
    }
    d[n]=b[n];
    sort(c,c+n+1);
    sort(d,d+n+1);
    for(i=0;i<=n;i++)
    {
        if(c[i]!=d[i])
        {
            check++;
        }
    }
    if(a[1]!=b[1] || a[n]!=b[n])
    {
        check++;
    }
    if(check==0)
    {
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}
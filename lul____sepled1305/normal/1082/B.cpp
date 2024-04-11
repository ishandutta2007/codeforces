#include<bits/stdc++.h>
using namespace std;
int n,s=0,maxi=0,dif=0,g=0,i,h=1;
string j;
char a[100005];
int b[100005];
int main()
{
    cin>>n;
    scanf("%s",&a);
    s=0;
    for(i=0;i<=100004;i++)
    {
        b[i]==0;
    }
    for(i=0;i<=n-1;i++)
    {
        if(a[i]=='G')
        {
            g++;
            if(a[i-1]!='G')
            {
                b[h]=0;
                h++;
            }
        }
        else
        {
            b[h]=g;
            h++;
            g=0;
        }
    }
    b[h]=g;
    g=0;
    for(i=1;i<=n+1;i++)
    {
        if(b[i]>0)
        {
            g++;
        }
    }
    if(g>=3){
    for(i=1;i<=n+1;i++)
    {
        if(b[i]==0)
        {
            h=b[i-1]+b[i+1]+1;
        }
        if(h>=maxi)
        {
            maxi=h;
        }
    }
    }
    else if(g==2)
    {
        for(i=1;i<=n+1;i++)
        {
            if(b[i]==0 && b[i-1]>0 && b[i+1]>0)
            {
                h=b[i-1]+b[i+1];
            }
            else if(b[i]==0)
            {
                h=b[i-1]+1;
            }
            if(h>=maxi)
            {
                maxi=h;
            }
        }
    }
    else if(g==1)
    {
        for(i=1;i<=n+1;i++)
        {
            if(b[i]>0)
            {
                maxi=b[i];
            }
        }
    }
    else if(g==0)
    {
        maxi=0;
    }
    cout<<maxi;
    return 0;
}
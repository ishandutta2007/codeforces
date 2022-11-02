#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,l;
long long a[200010];
long long b[200010];
int check(long long p)
{
    int wrong=0,place=0;
    for(i=1;i<n;i++)
    {
        if(i==1 && a[2]-a[1]!=p)
        {
            wrong++;
            if(a[3]-a[1]!=p && a[3]-a[2]!=p)
            {
                wrong++;
            }
            else if (a[3]-a[1]==p)
            {
                place=a[2];
            }
            else
            {
                place=a[1];
            }
            i++;
        }
        else if(a[i+1]-a[i]!=p && i==n-1)
        {
            wrong++;
            place=a[n];
        }
        else if(a[i+1]-a[i]!=p)
        {
            wrong++;
            if(a[i+2]-a[i]!=p)
            {
                wrong++;
            }
            else
            {
                place=a[i+1];
            }
            i++;
        }
    }
    if(wrong==0)
    {
        place=a[1];
    }
    if(wrong < 2)
    {
        for(k=1;k<=n;k++)
        {
            if(b[k]==place)
            {
                break;
            }
        }
        cout<<k;
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    if(n<4)
    {
        cout<<1;
    }
    else
    {
        if(check(a[2]-a[1])) {}
        else if (check(a[3]-a[2])) {}
        else if (check(a[3]-a[1])) {}
        else
        {
            cout<<-1;
        }
    }
    return 0;
}
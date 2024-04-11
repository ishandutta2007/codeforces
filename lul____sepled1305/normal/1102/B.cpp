#include<bits/stdc++.h>
using namespace std;
int n,k,i,ss;
int a[10000],b[10000],c[10000];
int main()
{
    cin>>n>>k;
    if(k>n)
    {
        ss++;
    }
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    for(i=0;i<10000;i++)
    {
        if(b[i]>k)
        {
            ss++;
        }
    }
    if(ss>0)
    {
        cout<<"NO";
    }
    else
    {
        for(i=0;i<10000;i++)
        {
            if(i==0)
            {
                c[i]=0;
            }
            else
            {
                c[i]=c[i-1]+b[i-1];
                c[i]%=k;
            }
        }
        cout<<"YES\n";
        for(i=0;i<n;i++)
        {
            cout<<c[a[i]]+1<<" ";
            c[a[i]]++;
            c[a[i]]%=k;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,i,f,Oh,miii;
int a[100010];
int b[100010];
int c[100010];
int d[100010];
int main(){
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    f=0;
    miii=0;
    a[n]=1000000;
    for(i=1;i<=n;i++)
    {
        if(a[i]-a[i-1]>0)
        {
            m=i-f;
            //cout<<m;
            if(m%(n-a[i-1])!=0)
            {
                Oh=1;
                break;
            }
            f=i;
        }
    }
    if(Oh==1)
    {
        cout<<"Impossible";
    }
    else
    {
        cout<<"Possible\n";
        for(i=0;i<n;i++)
        {
            c[b[i]]++;
        }
        for(i=0;i<n;i++)
        {
            c[i]=c[i]/(n-i);
        }
        for(i=1;i<n;i++)
        {
            c[i]+=c[i-1];
        }
        for(i=0;i<n;i++)
        {
            d[b[i]]++;
            cout<<c[b[i]-1]+(d[b[i]]-1)/(n-b[i])+1<<" ";
        }
    }
    return 0;
}
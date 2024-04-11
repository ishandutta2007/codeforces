#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];
long long i,j,k,neg,pos,t,n;
bool yes;

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        neg=0; pos=0; yes=true;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(j=0;j<n;j++)
        {
            cin>>b[j];
        }
        for(j=0;j<n;j++)
        {
            if(b[j]>a[j] && pos==0)
                yes=false;
            if(b[j]<a[j] && neg==0)
                yes=false;
            if(a[j]>0)
                pos++;
            if(a[j]<0)
                neg++;
        }
        if(yes)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
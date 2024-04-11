#include<bits/stdc++.h>
using namespace std;
int s[500000];
int b,k,i,j;
int main()
{
    cin>>b>>k;
    for(i=1;i<=k;i++)
    {
        cin>>s[i];
    }
    if(b%2==0)
    {
        if(s[k]%2==0)
        {
            cout<<"even";
        }
        else cout<<"odd";
    }
    else
    {
        for(i=1;i<=k;i++)
        {
            j+=s[i];
            j=j%2;
        }
        if(j%2==0)
        {
            cout<<"even";
        }
        else cout<<"odd";
    }
}
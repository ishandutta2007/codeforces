#include<bits/stdc++.h>
using namespace std;
int a,b,c,i,j,k,n,l;
int main()
{
    cin>>a>>b;
    if(a==1) cout<<0; else
    if(a-b<=0)
        {
            cout<<a-1;
        } else { j=b; for(i=2;i<=a;i++)
    {
        if(i<=a-b)
        {
            j+=i;
        }
    }cout<<j;}

}
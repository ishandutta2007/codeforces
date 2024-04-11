#include<bits/stdc++.h>
using namespace std;
long long a,n,i,j,k,o,pos,neg;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>j;
        if(j>0)
        {
            pos++;
        }
        if(j<0)
        {
            neg++;
        }
    }
    if(neg>=(n+1)/2)
    {
        cout<<-1;
    }
    else if(pos>=(n+1)/2)
    {
        cout<<1;
    }
    else cout<<0;
    return 0;
}
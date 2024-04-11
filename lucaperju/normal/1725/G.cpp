#include <bits/stdc++.h>
using namespace std;

long long v[100005];
int main()
{
    long long i,j,m,n,k=0,q,n1,n2;
    cin>>n;
    if(n==1)
        cout<<3;
    else if(n==2)
        cout<<5;
    else if(n==3)
        cout<<7;
    else if(n==4)
        cout<<8;
    else
    {
        n-=4LL;
        if(n%3LL==1LL)
        {
            cout<<9LL+4LL*(n/3LL);
        }
        else if(n%3LL==2LL)
        {
            cout<<11LL+4LL*(n/3LL);
        }
        else
            cout<<12LL+4LL*(n/3LL-1LL);
    }
    return 0;
}
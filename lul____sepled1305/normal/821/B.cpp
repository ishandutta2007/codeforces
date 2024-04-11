#include<bits/stdc++.h>
using namespace std;

long long a,b,c,n,i,j,m,maxi=0;

long long quickbanana(long long aa, long long bb)
{
    //printf("%d %d %d \n", aa,bb,((aa+1)*aa*(bb+1))/2 + ((bb+1)*(aa+1)*bb)/2);
    return ((aa+1)*aa*(bb+1))/2 + ((bb+1)*(aa+1)*bb)/2;
}

long long quick_x (long long x)
{
    if(x%m==0)
    {
        return b*m-x*m;
    }
    else
    {
        return b*m-x*m;
    }
}

int main()
{
    cin>>m>>b;
    for(i=0;i<=b;i++)
    {
        j=quickbanana(i,quick_x(i));
        //cout<<i<<" "<<j<<"\n";
        if(j>maxi)
        {
            maxi=j;
        }
    }
    cout<<maxi;
}
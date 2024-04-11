#include<bits/stdc++.h>
using namespace std;
long long n,i,j,k,l,m,p,x=1,y=1;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
    {
        printf("%lld %lld \n",x,y);
        if(n%2==0)
        {
            if(y==1 && x> n/2)
            {
                x=n+2-x;
            }
            else
            {
                if(x> n/2)
                {
                    y=m+2-y;
                }
                else
                {
                    y=m+1-y;
                }
                x=n+1-x;
            }
        }
        if(n%2==1)
        {
            if(y==1 && x> (n+1)/2)
            {
                x=n+2-x;
            }
            else if (x!=(n+1)/2)
            {
                if(x> (n+1)/2)
                {
                    y=m+2-y;
                }
                else
                {
                    y=m+1-y;
                }
                 x=n+1-x;
            }
            else
            {
                if(y>(m+1)/2)
                {
                    y=m+2-y;
                }
                else
                {
                    y=m+1-y;
                }
            }
        }
    }
    return 0;
}
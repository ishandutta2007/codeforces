#include <iostream>
#include <cstring> 
#include <cmath> 
using namespace std;

int n,k;

bool good(int x)
{
    int res=0;
    while (x>0)
    {
        res+=x;
        x/=k;
    }
    return (res>=n);
}


void main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d%d",&n,&k);
    int l=0;
    int r=n;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (good(m))
            r=m;
        else
            l=m;
    }
    printf("%d",r);

}
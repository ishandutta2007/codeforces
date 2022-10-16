#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
int v[200005];
int main()
{
    long long t,n,i,j=1,k,s=0,st,mx1=0,mx2=0,mn1=20000000,mn2=20000000;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(a>mx1)
        {
            mx2=mx1;
            mx1=a;
        }
        else
        if(a>mx2)
            mx2=a;
        if(a<mn1)
        {
            mn2=mn1;
            mn1=a;
        }
        else
        if(a<mn2)
            mn2=a;
    }
    cout<<min(mx2-mn1,mx1-mn2);
}
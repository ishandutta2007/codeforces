#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int d[2003][4];
int main()
{
    int n,a,b,cat,i,j,mx=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        if(a==1)
            ++d[i][0],++d[i][2];
        else
            ++d[i][1],++d[i][3];
        d[i][0]+=d[i-1][0];
        d[i][1]+=max(d[i-1][0],d[i-1][1]);
        d[i][2]+=max(max(d[i-1][0],d[i-1][1]),d[i-1][2]);
        d[i][3]+=max(max(d[i-1][0],d[i-1][1]),max(d[i-1][2],d[i-1][3]));
    }
    cout<<max(max(d[i-1][0],d[i-1][1]),max(d[i-1][2],d[i-1][3]));
}
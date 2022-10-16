#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int v[5005];
int main()
{
    int n,a,b,cat,i,j,mx=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(i=0;i<n;++i)
    {
        for(j=i+1;j<=n;++j)
        {
            if(v[j]-v[i]>(j-i)*100)
                mx=max(mx,j-i);
        }
    }
    cout<<mx;
}
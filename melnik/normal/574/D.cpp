#include <iostream>
#include <algorithm>
using namespace std;

int n,i[100000],z[100000],k,ma=-1;

void _go1(int k){
    z[k]=min(z[k-1]+1,min(i[k],z[k]));
}

void _go2(int k){
    z[k]=min(z[k+1]+1,min(i[k],z[k]));
}

int main()
{

    cin>>n;
    for (k=0;k<n;k++)
    {
        cin>>i[k];
        z[k]=2e9;
    }
    z[0]=1;
    z[n-1]=1;
    for (k=1;k<n;k++)
        _go1(k);
    for (k=n-2;k>=0;k--)
        _go2(k);
    for (k=0;k<n;k++)
        ma=max(ma,z[k]);
    cout<<ma;
    return 0;
}
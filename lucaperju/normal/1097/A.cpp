#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
long long v[200005];
char c[200005];
int main()
{
    long long n,i,j,m,mn=99999999999,mx=-999999999999,s=0,cnt=0,ok=0,k=0;
    char a,b,ac,bc;
    cin>>a>>b;
    for(i=1;i<=5;++i)
    {
        cin>>ac>>bc;
        if(ac==a || bc==b)
            ok=1;
    }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
}
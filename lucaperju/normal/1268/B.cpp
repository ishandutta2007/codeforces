#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    long long n,m,i,j,s=0,a=0,b=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        a+=x/2;
        b+=x/2;
        if(x&1)
        {
            if(i&1)
                ++a;
            else
                ++b;
        }
    }
    cout<<min(a,b);
    return 0;
}
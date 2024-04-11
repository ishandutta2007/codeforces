#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long long n,i,j,mx1=0,mx2=0,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        long long a;
        cin>>a;
        s+=a;
    }
    for(i=1;i<=n;++i)
    {
        long long b;
        cin>>b;
        if(b>mx1)
        {
            mx2=mx1;
            mx1=b;
        }
        else
        if(b>mx2)
            mx2=b;
    }
    if(mx1+mx2>=s)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
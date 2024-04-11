#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long long n,s=0,cr,i;
    cin>>n;
    for(i=2;i<=n;++i)
    {
        cr=n/i;
        --cr;
        s+=cr;
        s+=cr*(cr+1)/2;
    }
    cout<<s*4;
    return 0;
}
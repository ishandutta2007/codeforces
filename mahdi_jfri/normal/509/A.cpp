#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    n--;
    long long b=2*n;
    long long entekhab=1,zarb=1;
    for(int i=n;i>0;i--)
    {
        zarb*=i;
        entekhab*=b;
        b--;
    }
    cout<<entekhab/zarb;
}
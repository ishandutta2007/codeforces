#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll m[4];
    m[0]=a+b+c;
    m[1]=2*a+2*b;
    m[2]=2*a+2*c;
    m[3]=2*b+2*c;
    sort(m,m+4);
    cout<<m[0];
    return 0;
}
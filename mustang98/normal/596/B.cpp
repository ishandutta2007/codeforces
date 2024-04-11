#include <iostream>
#include <cmath>
using namespace std;
typedef long long int ll;

int main()
{
    ll n, rez=0,a,b;
    cin>>n;
    cin>>a;
    rez=abs(a);
    for (ll i=1;i<n;i++)
    {
        cin>>b;
        rez+=abs(b-a);
        a=b;
    }
    cout<<rez<<endl;
    return 0;
}
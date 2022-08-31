#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll p(int b)
{
    ll rez=1;
    for(int i=0;i<b;i++) rez*=2;
    return rez;
}

int main()
{
    ll n,an;
    cin>>n;
    an=6*n;
    ll R=(6+an)/2;
    R*=n;
    cout<<R+1;
    return 0;
}
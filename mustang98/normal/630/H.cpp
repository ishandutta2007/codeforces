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
    ll R=1,rez=1;
    ll n;
    cin>>n;
    R=n*(n-1)*(n-2)*(n-3)*(n-4);
    rez=R/120;
    rez*=R;
    cout<<rez;
    /*ll R;
    if (n<=10) {cout<<1; return 0;}
    n-=10;
    R=(n/6)*2;
    if (n%6>2) R+=2;
    else if (n%6>0) R++;
    cout<<R+1;*/
    return 0;
}
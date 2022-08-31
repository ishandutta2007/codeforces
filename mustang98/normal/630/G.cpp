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
    ll n,r1=0,r2=0;
    cin>>n;
    r1=n;//5
    r1+=n*(n-1);//4
    r1+=n*(n-1)+n*((n-1)*(n-2))/2;//3
    r1+=n*((n-1)*(n-2)*(n-3))/6+n*((n-1)*(n-2))/2;
    r1+=(n*(n-1)*(n-2)*(n-3)*(n-4))/120;
    //cout<<r1;
    r2=n;
    r2+=n*(n-1);
    r2+=(n*(n-1)*(n-2))/6;
    cout<<r1*r2;
    /*ll R;
    if (n<=10) {cout<<1; return 0;}
    n-=10;
    R=(n/6)*2;
    if (n%6>2) R+=2;
    else if (n%6>0) R++;
    cout<<R+1;*/
    return 0;
}
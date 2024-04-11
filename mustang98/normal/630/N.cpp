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
    double n,a,b,c,x1,x2;
    cin>>a>>b>>c;
    double d = b*b-4*a*c;
    x1 = -b+sqrt(d);
    x1/=(2*a);
    x2 = -b-sqrt(d);
    x2/=(2*a);
    cout.precision(40);
    cout<<max(x1,x2)<<endl;
    cout<<min(x1,x2);
    /*ll R;
    if (n<=10) {cout<<1; return 0;}
    n-=10;
    R=(n/6)*2;
    if (n%6>2) R+=2;
    else if (n%6>0) R++;
    cout<<R+1;*/
    return 0;
}
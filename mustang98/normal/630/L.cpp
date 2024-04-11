#include <iostream>
#include <cmath>
#include <string>

using namespace std;
typedef long long ll;

ll p(ll a)
{
    ;
}

int main()
{
    string s;
    cin>>s;
    ll n=0;
    n=(((int)s[0])-48)*10000+(((int)s[2])-48)*1000+(((int)s[4])-48)*100+(((int)s[3])-48)*10+(((int)s[1])-48);
    //cout<<n;
    ll R=1;
    for (int i=0;i<5;i++)
    {
        R*=n;
        R%=1000000;
    }
    R%=100000;
    //cin>>R;
    if (R<10) cout<<0;
    if (R<100) cout<<0;
    if (R<1000) cout<<0;
    if (R<10000) cout<<0;
    cout<<R;


    /*ll R;
    if (n<=10) {cout<<1; return 0;}
    n-=10;
    R=(n/6)*2;
    if (n%6>2) R+=2;
    else if (n%6>0) R++;
    cout<<R+1;*/
    return 0;
}
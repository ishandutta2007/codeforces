#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ll x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if ((x1==x2 && x2==x3) || (y1==y2 && y2==y3))
    {
        cout<<1;
        return 0;
    }

    //2 
    if (x1==x2 && (y3>=max(y1,y2) || y3<=min(y1,y2))) {cout<<2; return 0;}
    if (x1==x3 && (y2>=max(y1,y3) || y2<=min(y1,y3))) {cout<<2; return 0;}
    if (x2==x3 && (y1>=max(y2,y3) || y1<=min(y2,y3))) {cout<<2; return 0;}

    if (y1==y2 && (x3>=max(x1,x2) || x3<=min(x1,x2))) {cout<<2; return 0;}
    if (y1==y3 && (x2>=max(x1,x3) || x2<=min(x1,x3))) {cout<<2; return 0;}
    if (y2==y3 && (x1>=max(x2,x3) || x1<=min(x2,x3))) {cout<<2; return 0;}


    cout<<3;
    return 0;
}
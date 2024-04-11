#include <iostream>
using namespace std;

long long gcd(long long a,long long b)
{
    return(!(b)?a:gcd(b,a%b));
}
int main()
{
    int y,w,c;
    cin>>y>>w;
    if(y>w)
        c=6-y+1;
    else
        c=6-w+1;
    cout<<c/gcd(c,6)<<"/"<<6/gcd(c,6);
}
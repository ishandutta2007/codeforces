#include <iostream>
using namespace std;
int gcd ( int q, int w )
{
if (q<w)
swap (q, w);
while (w>0)
{
q=q%w;
if (q<w)
swap (q, w);
}
return q;
}
int main ()
{
int n, m;
cin>>n>>m;
cout<<gcd(n-1, m-1)+1;
return 0;
}
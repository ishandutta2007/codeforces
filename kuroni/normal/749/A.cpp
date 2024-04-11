#include <iostream>
using namespace std;
int n, i;
main()
{
    cin>>n;
    cout<<n/2<<'\n';
    for (i = 0; i < n/2 - 1; i++) cout<<2<<" ";
    if (n % 2) cout<<3; else cout<<2;
}
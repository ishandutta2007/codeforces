#include <iostream>

using namespace std;

int main()
{
    int n,m,a1,a2;
    cin>>n>>m;
    a1=m-1;
    a2=n-m;
    if (n==m&&m==1) cout<<1; else {
    if (a1==a2) cout<<a1;
    if (a1>a2) cout<<a1;
    if (a2>a1) cout<<++m;}
    return 0;
}
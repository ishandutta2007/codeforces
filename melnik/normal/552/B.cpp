#include <iostream>

using namespace std;

int main()
{
    long long n,kol=0,st=10,u=2;
    cin>>n;
    if (n<10) cout<<n; else {
    kol=9;
    while (st*10<=n)
    {
        kol+=u*(st*10-st);
        st*=10;
        u++;
    }
    kol+=u*(n-st+1);
    cout<<kol;}
    return 0;
}
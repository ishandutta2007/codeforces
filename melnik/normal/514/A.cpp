#include <iostream>
#include <string>
using namespace std;

int main()
{
    string r;
    cin>>r;
    int k=r.size(),n=0;
    if (r[0]=='9') {cout<<9; n=1;}
    for (int l=n;l<k;l++)
    if (r[l]>'4') cout<<'9'-r[l]; else cout<<r[l];
    return 0;
}
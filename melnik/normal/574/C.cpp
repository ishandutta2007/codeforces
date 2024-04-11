#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n,i[100000],k,z=0;
    cin>>n;
    for (k=0;k<n;k++)
        cin>>i[k];
    for (k=0;k<n;k++)
    {
        while (i[k]%2==0) i[k]/=2;
        while (i[k]%3==0) i[k]/=3;
    }
    for (k=1;k<n;k++)
        z=max(z,abs(i[k]-i[0]));
    if (z==0) cout<<"Yes"; else cout<<"No";
    return 0;
}
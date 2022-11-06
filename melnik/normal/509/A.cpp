#include <iostream>

using namespace std;

int main()
{
    long long n, t[10][10],k,f;
    cin>>n;
    for (k=0;k<n;k++)
    {
        t[k][0]=1;
        t[0][k]=1;
    }
    for (k=1;k<n;k++)
    for (f=1;f<n;f++)
    t[k][f]=t[k-1][f]+t[k][f-1];
    cout<<t[n-1][n-1];
    return 0;
}
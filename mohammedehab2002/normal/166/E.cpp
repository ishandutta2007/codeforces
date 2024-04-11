#include <iostream>
#include <string.h>
using namespace std;
#define mod 1000000007
int main()
{
    long long n,i,a=1;
    cin >> n;
    int arr[n+1];
    arr[1]=0;
    for (i=2;i<=n;i++)
    {
        a=(a*3)%mod;
        arr[i]=(a-arr[i-1]+mod)%mod;
    }
    cout << arr[n];
}
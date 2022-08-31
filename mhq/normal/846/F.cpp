#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

long long n;
int key[1000000+2];
int a[1000000+2];
int main()
{   cin>>n;
    long long curf = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        curf = curf + i - key[a[i]];
        key[ a[ i ] ] = i;
        ans+=curf;
    }
    long double t = 1. * ( 2*ans - n) / ( n * n);
    cout<<t;
     return 0;
}
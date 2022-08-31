#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

long long n, m, a, b, t;

long long kmin, kmax;

int main()
{   cin>>n>>m;
    kmax = ( n - m + 1) * ( n - m) / 2 ;
    a = n/m;
    b = (n + m - 1)/m;
    t = n % m;
    kmin = t * ( b * (b - 1))/2 + ( m - t) * ( a * ( a - 1) )/2;
    cout<<kmin<<" "<<kmax;
    return 0;
}
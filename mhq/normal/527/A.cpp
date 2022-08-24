#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
using namespace std;
long long gcd (long long a, long long b) {
    if ( a == 0 || b == 0) {
        return 0;
    }
    if ( b > a ) {
        swap(a,b);
    }
    return gcd(a % b, b) + a/b;
}
long long x,y;
int main()
{   ios_base::sync_with_stdio(false);
    cin>>x>>y;
    cout<<gcd(x,y);
    return 0;
}
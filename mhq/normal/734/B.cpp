#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int k2,k3,k5,k6;

int main()
{  cin>>k2>>k3>>k5>>k6;
   int t = min( min ( k2, k5) , k6);
   int ans = 256 * t;
   if ( k2 > t) {
       k2 = k2 - t;
       ans += 32*min(k2, k3);
   }
   cout<<ans;
    return 0;
}
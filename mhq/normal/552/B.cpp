#include <bits/stdc++.h>
using namespace std;

long long ans ( long long n) {
   int j = 1;
   int i;
   if ( n == 0) {
    return 0;
   }
   for ( i = 0; i < 10;i++) {
    if (  n < 10 * j ) {
        break;
    }
    j = j*10;
   }
   return ( ans( j - 1) + (i+1)*( n - j + 1));

}

int main() {
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
   long long n;
   cin>>n;
   cout<<ans(n);
   return 0;
}
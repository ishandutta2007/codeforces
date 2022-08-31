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
   int n,m;
   cin>>n>>m;
   if ( n == 1) {
    cout<<1;
    return 0;
   }
   if ( m > (n/2)) {
    cout<<(m-1);
   }
   else {
    cout<<(m+1);
   }
   return 0;
}
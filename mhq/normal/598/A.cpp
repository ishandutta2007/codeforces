#include <bits/stdc++.h>
using namespace std;


int main() {
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
   long long n;
   int t;
   cin>>t;
   for ( int i = 0; i < t; i++) {
        cin>>n;
        int nu = 1;
        while ( nu <= n) {
            nu = nu*2;
        }
        cout<< n*(n+1)/2 - 2*(nu - 1)<<endl;
   }
   return 0;
}
#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int main()
{    int n;
     cin>>n;
     int a[n];
     for ( int i = 0; i < n; i ++ ) {
        cin>>a[i];
     }
     int ans = 0;
     int curans = 0;
     for ( int i = 0; i < n; i ++ ) {
        if ( a[i] == 0) {
        for ( int j = 0; j < n; j++) {
            if ( (a[j] == 0 && j <= i) || (a[j] == 1) && ( i < j)) {
              curans++;
            }
        }
        ans = max(curans,ans);
        curans = 0;
        }
     }
     for ( int i = 0; i < n; i ++) {
        if ( a[i] == 1) {
            curans++;
        }
     }
     cout<<max(ans,curans);
     return 0;
}
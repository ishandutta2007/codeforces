#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

long long n,k;

long long t[49];

long long M;

long long  ans( int a, int b) {
    long long time = 0;
    for ( int i = 0; i < a; i++) {
        time += n*t[i];
    }
    for ( int i = a ; i < k; i++) {
        time += b*t[i];
    }
    if ( time > M ) {
        return 0;
    }
    long long cur = 0;
    cur += n*a;
    cur += (k - a)*b;
    cur += b;
    cur += min(( M - time)/(t[a]), n - b);
    return cur;
}
int main()
{    cin>>n>>k>>M;
     for ( int i = 0; i < k; i++) {
        cin>>t[i];
     }
     sort(t,t+k);
     long long curans = 0;
     int cura;
     int curb;
     for ( int i = 0; i < k; i++) {
        for ( int j = 0; j <= n; j++) {
               if ( curans < ans(i,j) ) {
                    curans = ans(i,j);
               }
         }
     }
     cout<<curans;
     return 0;
}
#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int n;


int main()
{   cin>>n;
    if ( n == 0 ) {
        cout<<1;
    }
    else {
    n = n % 4 + 4;
    int t = 1;
    for ( int i = 0; i < n; i++){
        t = t * 8;
    }
    cout<< t  % 10;
    }
    return 0;
}
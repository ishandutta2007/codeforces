#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{   ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if ( n % 2 == 1) {
        cout<<(n-1)/2<<" "<<(n+1)/2;
    }
    else if ( n % 4 == 0) {
        cout<<n/2 - 1<<" "<<n/2 + 1;
    }
    else {
        cout<<n/2 - 2<<" "<<n/2 + 2;
    }

     return 0;
}
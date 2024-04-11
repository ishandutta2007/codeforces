#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{   ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    if ( k == 0 || k == n) {
        cout<<0<<" ";
    }
    else {
        cout<<1<<" ";
    }
    cout<<min(2*k,n-k);
     return 0;
}
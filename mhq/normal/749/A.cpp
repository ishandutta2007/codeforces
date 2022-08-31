#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int n;


int main()
{   cin>>n;
    if ( n % 2 ==0 ) {
        cout<<n/2<<endl;
        for ( int i = 0; i < n/2; i++ ) {
            cout<<2<<" ";
        }
    }
    else {
        cout<<(n-1)/2<<endl;
        cout<<3<<" ";
        for (int i = 0; i < (n-3)/2;i++){
            cout<<2<<" ";
        }
    }
    return 0;
}
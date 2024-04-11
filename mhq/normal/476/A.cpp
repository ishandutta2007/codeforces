#include <iostream>

using namespace std;

int n,m;
int main()
{   cin>>n>>m;
    int t = ( n + 1 ) / 2;
    if ( m  > n ) {
        cout<<-1;
    }
    else {
    cout<< t  + (( 100000*m - t ) % m);
    }
    return 0;
}
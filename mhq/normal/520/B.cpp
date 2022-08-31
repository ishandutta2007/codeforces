#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int n, m;

int dfs (int a, int b) {
    if ( a >= b) {
        return (a - b);
    }
    else {
        if (  a == 1 ) {
            return ( dfs(2,b) + 1);
        }
        if (  a == 2 ) {
            return ( dfs(4,b) + 1 );
        }
        else {
        int t = dfs(2*a-2, b);
        int l = dfs(2*a, b);
        return(min( t + 2, l + 1));
    }
}
}
int main()
{   cin>>n>>m;
    bool flag = false;
    int ans = 1e5;
    if ( m == 1) {
        flag = true;
    }
    else {
        for ( int i = n; i >= 1; i-- ) {
            ans = min( ans, dfs ( i, m) + n - i);
        }
    }
    if ( flag ) {
        cout<< n - 1;
    }
    else {
        cout<<ans;
    }
    return 0;
}
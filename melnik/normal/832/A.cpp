#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
using namespace std;


int main()
{

//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    long long n, k;
    cin >> n >> k;
    if ( ( n / k ) & 1 )
        puts( "YES" );
    else
        puts( "NO" );
    return 0;
}
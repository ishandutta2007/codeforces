#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
 
typedef long long i64;


long long gcd(long long a, long long b)
{
    while(b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    long long n;
    cin >> n;
    
    long long res = 0;
    for (long long a = max(1ll, n - 200); a <= n; ++a)
        for (long long b = a; b <= n; ++b)
            for (long long c = b; c <= n; ++c)
                res = max(res, lcm(lcm(a, b), c));
    
    cout << res;
    
    return 0;
}
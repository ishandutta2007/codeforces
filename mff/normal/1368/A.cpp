#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <array>
#include <complex>
 
#define endl '\n'
 
using namespace std;
 
void solve()
{
    long long a, b, n;
    cin >> a >> b >> n;
 
    int s = 0;
 
    while (true)
    {
        if (b > a)
            swap(a, b);
 
        if (a > n)
            break;
 
        b += a;
        s++;
    }
 
    cout << s << endl;
}
 
int main()
{
 
    int t;
    cin >> t;
 
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
 
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>

typedef unsigned long long ull;

const long double eps = 1e-7;
const long long inf = 1e18;

using namespace std;

int main (int argc, const char * argv[])
{
    int n, a[7], ans = 0;
    cin >> n;
    for (int i = 0; i < 7; i++) cin >> a[i];
    while (n != 0)
    {
        for (int i = 0; i < 7; i++)
        {
            if (n == 0) continue;
            n -= a[i];
            ans = i + 1;
            n = max(n, 0);
        }
    }
    cout << ans;
    return 0;
}
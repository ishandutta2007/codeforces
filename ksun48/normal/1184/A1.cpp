#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(0);

    ll R;
    cin >> R;
    for (ll x = 1; x <= 1000000; x++)
    {
        ll v = R - x * x - x - 1;
        if (v > 0 && v % (2 * x) == 0)
        {
            cout << x << " " << v / (2 * x) << "\n";
            return 0;
        }
    }
    cout << "NO\n";
}
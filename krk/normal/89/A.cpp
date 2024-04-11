#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, k;

int main()
{
    cin >> n >> m >> k;
    if (n % 2 == 0) cout << "0\n";
    else {
         int best = 1000000;
         for (int i = 0; i < n; i++) {
             int a;
             cin >> a;
             if (i % 2 == 0) best = min(best, a);
         }
         int permin = m / ((n + 1) / 2);
         cout << min(ll(best), ll(k) * ll(permin)) << endl;
    }
    return 0;
}
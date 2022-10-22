#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 2001;

int n;
long long best[Maxn];

int main()
{
    int tim;
    long long cost;
    fill(best+1, best+Maxn, 100000000000000LL);
    cin >> n;
    for (int nn = 0; nn < n; nn++) {
          cin >> tim >> cost; tim++;
          for (int i = n; i > 0; i--)
             best[i] = min(best[i], best[max(0, i-tim)] + cost);
    }
    cout << best[n] << endl;
    return 0;
}
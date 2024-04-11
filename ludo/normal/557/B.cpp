#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 100000

typedef long long ll;

int a[2 * MAXN];

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 2 * n; --i >= 0;) {
		cin >> a[i];
    }
    sort(a, a + 2 * n);

    ll sumgirl = 1LL * a[0] * n;
    ll sumboy = 1LL * a[n] * n;

    double sg = sumgirl, sb = sumboy, sw = w;

    double ans = sw;
    if (3.0 * sg < ans) ans = 3.0 * sg;
    if (1.5 * sb < ans) ans = 1.5 * sb;
//    double ans = min(3.0 * sg, 1.5 * sb, sw);

    cout.precision(10);
    cout << ans << endl;


//    int twice = min(6 * sumgirl, 3 * sumboy);
//    twice = min(twice, 2 * w);
//
//    cout << (twice / 2);
//    if (twice % 2 != 0) {
//		cout << ".5";
//    }
//    cout << endl;

    return 0;
}
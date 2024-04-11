#include <algorithm>
#include <iostream>
#include <vector>
#include <memory.h>
#define pb push_back
#define all(a) begin(a), end(a)

using namespace std;

const int N = 3001;

int64_t a[N], d[N][N], n;
vector<int64_t> b;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], a[i] -= i, b.pb(a[i]);
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    int m = b.size();
    memset(d, 63, sizeof(d));
    for (int i = 0; i < m; ++i)
        d[0][i] = abs(a[0] - b[i]);
    for (int i = 1; i < n; ++i)
    for (int64_t j = 0, ml = d[N][-1]; j < m; ++j)
        ml = min(ml, d[i - 1][j]), d[i][j] = min(d[i][j], ml + abs(a[i] - b[j]));
    cout << *min_element(all(d[n - 1]));
    return 0;
}
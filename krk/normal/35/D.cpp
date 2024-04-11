#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 10001;

int n, x, best[Maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        c *= n - i;
        for (int j = x; j >= c; j--) best[j] = max(best[j], best[j-c]+1);
    }
    cout << best[x] << endl;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

int a[MAX];
int b[MAX + 1] = {}; // last occurence of a certain number
int d[MAX + 1] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = 0;
        d[i] = 0;
    }

    d[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        d[i] = d[i + 1];
        if (b[a[i]] == 0) {
            b[a[i]] = i;
            d[i]++;
        }
    }

    for (int i = 0; i < m; i++) {
        int l;
        cin >> l;
        cout << d[l - 1] << endl;
    }

    return 0;
}
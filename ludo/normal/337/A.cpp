#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <vector>
#include <utility>

using namespace std;

#define MAX 50

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int val[MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> val[i];
    }

    sort(val, val + m);

    n--;
    int ret = 1000;
    for (int i = 0; i + n < m; i++) {
        ret = min(ret, val[i + n] - val[i]);
    }
    cout << ret << endl;
    return 0;
}
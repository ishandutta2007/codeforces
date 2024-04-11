#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> pii;

int a[10], v, bi = 1;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    bool p = false;
    cin >> v;
    for (int i = 1; i < 10; i++) {
        cin >> a[i];
        if (v >= a[i]) {
            p = true;
        }
        if (a[i] <= a[bi]) {
            bi = i;
        }
    }

    if (!p) {
        cout << -1 << endl;
    }

    int n = v / a[bi];
    string s(n, '0' + bi);

    ll rem = v - a[bi] * n;
    for (int k = 0; k < n && rem > 0; k++) {
        int i = 9;
        while (i >= bi && rem + a[bi] - a[i] < 0) {
            i--;
        }
        if (i < bi) {
            break;
        }
        rem += a[bi] - a[i];
        s[k] = '0' + i;
    }
    cout << s << endl;
    return 0;
}
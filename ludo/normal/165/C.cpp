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
#define MAX 1003006

typedef long long ll;
typedef pair<int, int> pii;

int k, n = 0, nv = 0;
ll v[MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> k;

    v[nv++] = 0;

    char c;
    cin.get(c);
    cin.get(c);
    while (cin && c != '\n') {
        n++;
        if (c == '1') {
            v[nv++] = n;
        }

        cin.get(c);
    }

    v[nv++] = ++n;

    ll ret = 0;
    if (k == 0) {
        for (int i = 1; i < nv; i++) {
            ret += (v[i] - v[i - 1]) * (v[i] - v[i - 1] - 1) / 2;
        }
    } else {
        for (int i = 1; i + k < nv; i++) {
            ret += (v[i] - v[i - 1]) * (v[i + k] - v[i + k - 1]);
        }
    }

    cout << ret << endl;
    return 0;
}
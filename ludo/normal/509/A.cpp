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
#define MAXN 100

typedef long long ll;
typedef pair<int, int> pii;

int table[MAXN][MAXN];

int n;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;

    int maxnum = 1;
    for (int i = 0; i < n; i++) {
        table[0][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        table[i][0] = 1;
        for (int j = 1; j < n; j++) {
            table[i][j] = table[i - 1][j] + table[i][j - 1];
            maxnum = max(maxnum, table[i][j]);
        }
    }
    cout << maxnum << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

const int maxn = 2010;

string digits[maxn];
int best[maxn][maxn];
int to[maxn][10];

string gMask[10] = {
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

int calculate(int ix, int digit) {
    int ans = 0;
    for (int i = 0; i < 7; ++i) {
        if (digits[ix][i] == '1' && gMask[digit][i] == '0'){
            return maxn;
        }

        if (digits[ix][i] == '0' && gMask[digit][i] == '1')
            ans++;
    }
    return ans;
}

bool solve(int n, int k) {
    if (n == -1)
        return k == 0;

    int &ans = best[n][k];

    if (ans != -1)
        return ans >= 0;

    for (int i = 9; i >= 0; --i) {
        if (to[n][i] <= k && solve(n - 1, k - to[n][i])) {
            ans = i;
            return true;
        }
    }

    ans = -2;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> digits[n - i - 1];
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 10; ++j) {
            to[i][j] = calculate(i, j);
        }

    memset(best, -1, sizeof best);

    if (solve(n - 1, k)) {
        for (int i = n - 1; i >= 0; --i) {
            cout << best[i][k];
            k -= to[i][best[i][k]];
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
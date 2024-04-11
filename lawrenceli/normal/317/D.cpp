#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <map>
#include <cstring>
#include <cassert>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;

const int maxsq = 32000;

int n;
unordered_map<int, int> dp;

int calc(int x) {
    //cout << x << endl;
    if (dp.count(x)) return dp[x];

    bool good[15];
    memset(good, 0, sizeof(good));
    for (int i = 1; i < 30; i++)
        if (x & 1<<i) {
            int y = x;
            for (int j = i; j < 30; j += i)
                y &= ~(1<<j);
            good[calc(y)] = 1;
        }

    for (int i = 0; i < 30; i++)
        if (!good[i])
            return dp[x] = i;
    assert(0);
}

bool used[maxsq];
int freq[30];


int main() {
    cin >> n;

    dp[0] = 0;
    dp[(1<<30) - 2] = 12;

    int tot = n + 1 - maxsq;
    freq[1]++;
    for (int i = 2; i < maxsq; i++) {
        if (i > n) continue;
        if (used[i]) continue;
        int num = 0;
        for (ll j = i; j <= n; j *= i) {
            num++;
            if (j < maxsq) used[j] = 1;
            else tot--;
        }
        freq[num]++;
    }

    freq[1] += max(0, tot);

    int nim = 0;
    for (int i = 1; i < 30; i++)
        if (freq[i] & 1)
            nim ^= calc((1<<(i+1)) - 2);

    cout << (nim ? "Vasya\n" : "Petya\n");
}
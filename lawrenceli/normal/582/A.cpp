#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

const int maxn = 505;
const int maxm = 505 * 505;

int n, m, ar[maxm];
bool good[maxm];
int num[maxm], cnt;
int temp[maxm], sze;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main() {
    cin >> n;
    m = n * n;
    for (int i = 0; i < m; ++i) cin >> ar[i];
    sort(ar, ar+m);
    reverse(ar, ar+m);

    for (int i = 0; i < m; ++i) good[i] = 1;
    for (int i = 0; i < m; ++i)
        if (good[i]) {
            num[cnt++] = ar[i];
            sze = 0;
            for (int j = 0; j < cnt - 1; ++j) {
                int g = gcd(num[cnt-1], num[j]);
                temp[sze++] = g, temp[sze++] = g;
            }
            sort(temp, temp + sze); reverse(temp, temp + sze);

            int p = 0;
            for (int j = i+1; j < m; ++j)
                if (p < sze && temp[p] == ar[j] && good[j]) {
                    good[j] = 0, p++;
                }
        }

    assert(n == cnt);
    for (int i = 0; i < n; ++i) cout << num[i] << ' ';
    cout << '\n';
}
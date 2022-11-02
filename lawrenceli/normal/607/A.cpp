#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ios>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;

const int maxn = 100100;

int n;
pii ar[maxn];
int ans[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    ar[0].A = -1e9;
    for (int i = 1; i <= n; i++)
        cin >> ar[i].A >> ar[i].B;
    n++;

    sort(ar, ar + n);
    ans[0] = 0;
    for (int i = 1; i < n; i++) {
        int x = lower_bound(ar, ar + n, pii(ar[i].A - ar[i].B, -1)) - ar - 1;
        ans[i] = ans[x] + 1;
    }

    int ma = 0;
    for (int i = 0; i < n; i++)
        ma = max(ma, ans[i]);

    cout << n - 1 - ma << '\n';
}
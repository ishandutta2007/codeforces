/**
 * @author Macesuted (macesuted@qq.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define maxn 2500

typedef pair<int, int> pii;

int a[maxn];

vector<int> answer;

int find(int v) {
    for (register int i = 1;; i++)
        if (a[i] == v) return i;
    return -1;
}
void reverse(int p) {
    if (p == 1) return;
    reverse(a + 1, a + p + 1);
    answer.push_back(p);
    return;
}

void work(void) {
    int n;
    cin >> n;
    for (register int i = 1; i <= n; i++) cin >> a[i];
    for (register int i = 1; i <= n; i++)
        if (a[i] % 2 != i % 2) return cout << -1 << endl, void();
    answer.clear();
    for (register int i = n; i > 1; i -= 2) {
        if (a[i] == i && a[i - 1] == i - 1) continue;
        int p = find(i);
        reverse(p);
        p = find(i - 1);
        reverse(p - 1);
        reverse(p + 1);
        reverse(3);
        reverse(i);
    }
    cout << answer.size() << endl;
    for (vector<int>::iterator i = answer.begin(); i != answer.end(); i++) cout << *i << ' ';
    cout << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    int _ = 1;
    cin >> _;
    while (_--) work();
    return 0;
}
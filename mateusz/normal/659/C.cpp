#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
int a[N];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + 1 + n);

    int in = 1;
    int v = 1;
    vector<int> ans;

    while (m >= v) {
        if (in <= n && a[in] == v) {
            v++;
            in++;
        } else {
            m -= v;
            ans.push_back(v);
            v++;
        }
    }

    printf("%d\n", ans.size());
    for (int x: ans) {
        printf("%d ", x);
    }

    return 0;
}
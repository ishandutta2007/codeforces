#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, d, h;

int main() {

    scanf("%d %d %d", &n, &d, &h);
    if (d == 1 && h == 1 && n > 2 || d > 2 * h) {
        printf("-1\n");
        return 0;
    }

    vector<pair<int, int> > edges;
    for (int i = 2; i <= min(h, d) + 1; i++) {
        edges.push_back(make_pair(i - 1, i));
    }

    int last = 1;
    for (int i = min(h, d) + 2; i <= d + 1; i++) {
        edges.push_back(make_pair(last, i));
        last = i;
    }
    for (int i = d + 2; i <= n; i++) {
        edges.push_back(make_pair(h > 1 ? 2 : 1, i));
    }

    for (auto e: edges) {
        printf("%d %d\n", e.first, e.second);
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf = 1e9 + 5;

int n, start, x;
int val[50100], nxt[50100];
int seed;
int ans = inf;

void ask(int p) {
    cout << "? " << p << endl;
    int v, t;
    cin >> v >> t;
    if (v == -1 && t == -1) exit(0);
    val[p] = v, nxt[p] = t;
    if (v >= x) ans = min(ans, v);
}

void answer(int _ans) {
    cout << "! " << _ans << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> start >> x;
    for (int i = 1; i <= n; i++) val[i] = nxt[i] = -2;
    ask(start);
    if (val[start] >= x) answer(val[start]);

    seed = n + start + x + val[start] + nxt[start];
    srand(seed);

    assert(ll(RAND_MAX) * RAND_MAX > 50000);

    for (int t = 0; t < 1498; t++) {
        int p = ll(rand()) * rand() % n + 1;
        ask(p);
        seed += val[p] + nxt[p];
        srand(seed);
    }

    int p = -1, v = -1;
    for (int i = 1; i <= n; i++)
        if (val[i] != -2 && val[i] < x && val[i] > v)
            p = i, v = val[i];

    p = nxt[p];

    for (int t = 0; t < 500; t++) {
        if (p == -1) break;
        ask(p);
        p = nxt[p];
    }

    if (ans == inf) answer(-1);
    else answer(ans);
}
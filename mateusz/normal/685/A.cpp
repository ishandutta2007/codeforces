#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bool used[10];
int position[N];
int n, m, l1, l2;
int ans;

bool good() {
    long long w1 = 0, w2 = 0;;
    for (int i = 0; i < l1; i++) {
        w1 = 7 * w1 + position[i];
    }
    if (w1 >= n) {
        return false;
    }

    for (int i = l1; i < l1 + l2; i++) {
        w2 = 7 * w2 + position[i];
    }
    if (w2 >= m) {
        return false;
    }

    return true;
}

void solve(int w, int l) {
    if (w == l) {
        if (good()) {
            ans++;
        }
        return;
    }

    for (int i = 0; i < 7; i++) {
        if (used[i] == false) {
            position[w] = i;
            used[i] = true;
            solve(w + 1, l);
            used[i] = false;
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    int _n = n;
    int _m = m;
    _n--;
    _m--;
    while (_n > 0) {
        l1++;
        _n /= 7;
    }
    if (n == 1) {
        l1++;
    }
    while (_m > 0) {
        l2++;
        _m /= 7;
    }
    if (m == 1) {
        l2++;
    }

    if (l1 + l2 > 7) {
        printf("0\n");
        return 0;
    }

    solve(0, l1 + l2);

    printf("%d\n", ans);

    return 0;
}
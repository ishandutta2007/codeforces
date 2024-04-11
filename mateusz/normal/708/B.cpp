#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int ans[N + 5];
int a_00, a_01, a_10, a_11;

bool solve(int w, int zeros, int ones, int a, int b) {
    if (a == 0 && b == 0 && zeros == 0 && ones == 0) {
        return true;
    }

    if (a < 0 || b < 0 || a + b != (long long)zeros * ones) {
        return false;
    }

    if (zeros > 0 && solve(w + 1, zeros - 1, ones, a - ones, b)) {
        ans[w] = 0;
        return true;
    } else if (ones > 0) {
        ans[w] = 1;
        return solve(w + 1, zeros, ones - 1, a, b - zeros);
    } else {
        return false;
    }
}

int main() {

    scanf("%d %d %d %d", &a_00, &a_01, &a_10, &a_11);

    if (a_00 == 0 && a_01 == 0 && a_10 == 0 && a_11 == 0) {
        printf("1\n");
        return 0;
    }
    int start = (a_10 + a_01) > 0 ? 1 : 0;
    int zeros = -1;
    for (int i = start; i <= N; i++) {
        if ((long long)i * (i - 1) / 2 == a_00) {
            zeros = i;
            break;
        }
    }
    int ones = -1;
    for (int i = start; i <= N; i++) {
        if ((long long)i * (i - 1) / 2 == a_11) {
            ones = i;
            break;
        }
    }

    long long tmp = a_01 + a_10;
    if (zeros == -1 || ones == -1 || tmp != (long long)zeros * ones) {
        printf("Impossible\n");
        return 0;
    }

    if (!solve(1, zeros, ones, a_01, a_10)) {
        printf("Impossible\n");
        return 0;
    }

    for (int i = 1; i <= zeros + ones; i++) {
        printf("%d", ans[i]);
    }

    return 0;
}
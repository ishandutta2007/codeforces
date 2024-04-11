#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, t;
int digit[N];

bool divisible(int t) {
    int mod = 0;
    for (int i = 1; i <= n; i++) {
        mod *= 10;
        mod += digit[i];
        mod %= t;
    }
    return mod == 0;
}

int main() {

    srand(53151);

    scanf("%d %d", &n, &t);

    for (int i = 1; i <= n; i++) {
        digit[i] = rand() % 10;
    }
    if (digit[1] == 0) {
        digit[1] = 1;
    }
    int cnt = 0;
    do {
        cnt++;
        int x = rand() % n + 1;
        digit[x] = rand() % 10;

        if (digit[1] == 0) {
            digit[1] = 1;
        }
    } while (divisible(t) == false && cnt < 10000);

    if (cnt == 10000) {
        printf("-1\n");
    } else {
        for (int i = 1; i <= n; i++) {
            printf("%d", digit[i]);
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;

bool isPrime(int w) {
    if (w == 1) {
        return false;
    }
    for (int i = 2; i * i <= w; i++) {
        if (w % i == 0) {
            return false;
        }
    }
    return true;
}

bool canSolve(int w, int steps) {
    if (w == 0) {
        return true;
    }
    if (steps == 1) {
        return isPrime(w);
    } else {
        for (int i = 2; i <= min(w, 20); i++) {
            if (isPrime(i) && canSolve(w - i, steps - 1)) {
                return true;
            }
        }
    }
    return false;
}

void solve(int n, int steps) {
    if (n == 0 || steps == 0) {
        return;
    }
    for (int i = n; i >= 1; i--) {
        if (isPrime(i) && canSolve(n - i, steps - 1)) {
            if (steps == 3) {
                if (n - i == 0) {
                    printf("1\n");
                } else if (isPrime(n - i)) {
                    printf("2\n");
                } else {
                    printf("3\n");
                }
            }
            printf("%d ", i);
            solve(n - i, steps - 1);
            break;
        }
    }
}

int main() {

    scanf("%d", &n);
    solve(n, 3);
    return 0;
}
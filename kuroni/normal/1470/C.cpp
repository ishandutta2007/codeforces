#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int D = 333;

int n, k;

void answer(int u) {
    cout << "! " << u + 1 << endl;
    exit(0);
}

int ask(int u) {
    cout << "? " << u + 1 << endl;
    int ret; cin >> ret; return ret;
}

void test(int u) {
    if (int tmp = ask(u); tmp != k) {
        if (tmp > k) {
            while (true) {
                (u += n - 1) %= n;
                if (ask(u) == k) {
                    answer(u);
                }
            }
        } else {
            while (true) {
                (u += 1) %= n;
                if (ask(u) == k) {
                    answer(u);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    int st = 0;
    while (__gcd(D, n) != 1) {
        D++;
    }
    while (true) {
        test(st); (st += D) %= n;
    }
}
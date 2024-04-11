#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

multiset<int> S;
int q, value;
char type;

int solve(multiset<int>::iterator from, multiset<int>::iterator to, int bit, int value, int curVal) {
    if (bit < 0) {
        if (from != S.end()) {
            return *from;
        } else {
            return 0;
        }
    }
    if (value & (1 << bit)) {
        auto it = S.lower_bound(curVal | (1 << bit));
        if (it == from) {
            return solve(from, to, bit - 1, value, curVal ^ (1 << bit));
        } else {
            solve(from, it, bit - 1, value, curVal);
        }
    } else {
        curVal |= (1 << bit);
        auto it = S.lower_bound(curVal);
        if (it == S.end() || (to != S.end() && *to <= *it)) {
            return solve(from, to, bit - 1, value, curVal ^ (1 << bit));
        } else {
            return solve(it, to, bit - 1, value, curVal);
        }
    }
}

int main() {

    S.insert(0);
    scanf("%d", &q);
    while (q--) {
        scanf(" %c %d", &type, &value);
        if (type == '+') {
            S.insert(value);
        } else if (type == '-') {
            S.erase(S.lower_bound(value));
        } else {
            printf("%d\n", solve(S.begin(), S.end(), 29, value, 0) ^ value);
        }
    }

    return 0;
}
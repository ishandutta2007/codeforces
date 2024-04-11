#include <bits/stdc++.h>

using namespace std;

long long NWD(long long a, long long b) {
    return b ? NWD(b, a % b) : a;
}

long long divide(long long t, long long a, long long b) {
    if (t / b + 1 >= a / NWD(a, b)) {
        return t / (a / NWD(a, b) * b) * min(a, b);
    }
    return 0;
}

long long rest(long long t, long long a, long long b) {
    if (t / b + 1 >= a / NWD(a, b)) {
        return min(t % (a / NWD(a, b) * b) + 1, min(a, b));
    }
    return min(min(t + 1, a), b);
}

long long t, a, b;

int main() {

    cin >> t >> a >> b;
    if (a > b) {
        swap(a, b);
    }

    cerr << divide(t, a, b) << " " << rest(t, a, b) << endl;
    long long goodDists = divide(t, a, b) + rest(t, a, b) - 1;

    cout << goodDists/NWD(goodDists, t) << "/" << t / NWD(goodDists, t) << "\n";

    return 0;
}
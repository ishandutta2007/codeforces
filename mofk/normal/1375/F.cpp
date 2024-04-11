#include <bits/stdc++.h>

using namespace std;

long long a[4];
int go(long long x) {
    cout << x << endl;
    int y;
    cin >> y;
    if (y == 0) exit(0);
    return y;
}
long long mx(void) {
    return max(a[1], max(a[2], a[3]));
}
long long val(void) {
    return mx() * 3 - (a[1] + a[2] + a[3]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a[1] >> a[2] >> a[3];
    cout << "First" << endl;

    long long x = val();
    int y = go(x);
    if (a[y] != mx()) {
        a[y] += x;
        x = val() / 3;
        go(x);
        assert(false);
    }
    else {
        a[y] += x;
        x = val();
        y = go(x);
        a[y] += x;
        x = val() / 3;
        go(x);
        assert(false);
    }
    return 0;
}
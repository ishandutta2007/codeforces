#include <bits/stdc++.h>

using namespace std;

map<int, int> before;

inline int ask(int pos) {
    if (before.find(pos) != before.end())
        return before[pos];
    cout << "? " << pos + 1 << endl;
    int x;
    cin >> x;
    before[pos] = x;
    if (x == 1) {
        cout << "! " << pos + 1 << endl;
        exit(0);
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    if (n == 1)
        return cout << "! 1\n", 0;

    int fir = ask(0), sec = ask(1);
    if (sec > fir)
        return cout << "! 1\n", 0;
    fir = ask(n - 2), sec = ask(n - 1);
    if (sec < fir)
        return cout << "! " << n << '\n', 0;

    int l = 1, r = n - 1;
    while (r - l > 2) {
        cerr << "l = " << l << " r = " << r << endl;
        int mid = (l + r) / 2;
        fir = ask(mid), sec = ask(mid + 1);
        if (fir > sec)
            l = mid + 1;
        else
            r = mid + 1;
    }

    int prev = ask(l - 1), cur = ask(l), nxt = ask(l + 1);
    if (prev > cur && cur < nxt)
        cout << "! " << l + 1 << endl;
    else
        cout << "! " << l + 2 << endl;
}
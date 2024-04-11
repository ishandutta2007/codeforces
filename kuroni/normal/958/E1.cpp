#include <bits/stdc++.h>

using namespace std;

struct po {
    int x, y;
    po (int _x = 0, int _y = 0): x(_x), y(_y) {}
};

vector<po> a, b;

long long S (po a, po b, po c) {
    return 1LL * (a.x - b.x) * (a.y + b.y) + 1LL * (b.x - c.x) * (b.y + c.y) + 1LL * (c.x - a.x) * (c.y + a.y);
}

bool inter (po a, po b, po x, po y) {
    long long u = S(a, b, x), v = S(a, b, y);
    if (u * v > 0)
        return false;
    u = S(x, y, a), v = S(x, y, b);
    if (u * v > 0)
        return false;
    return true;
}

bool ok (vector<po> a, vector<po> b) {
    for (int i = 0; i < (int)a.size(); ++i)
        for (int j = i + 1; j < (int)a.size(); ++j)
            if (inter(a[i], b[i], a[j], b[j]))
                return false;
    return true;
}

void solve (int B) {
    vector<int> c;
    for (int i = 0; i < B; ++i)
        c.push_back(i);
    do {
        vector<po> d;
        for (int i = 0; i < B; ++i)
            d.push_back(b[c[i]]);
        if (ok(a, d)) {
            cout << "Yes" << endl;
            return;
        }
    } while (next_permutation(c.begin(), c.end()));
    cout << "No" << endl;
}

int main() {
    int R, B, x, y;
    cin >> R >> B;
    if (R != B) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < R; ++i) {
        cin >> x >> y;
        a.push_back(po(x, y));
    }
    for (int i = 0; i < B; ++i) {
        cin >> x >> y;
        b.push_back(po(x, y));
    }
    solve(B);
    return 0;
}
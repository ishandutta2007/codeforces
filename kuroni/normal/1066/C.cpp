#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int q, id, l = 1, r = 0, pos[N];
char c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        cin >> c >> id;
        if (c == 'R') {
            pos[id] = ++r;
        } else if (c == 'L') {
            pos[id] = --l;
        } else {
            cout << min(pos[id] - l, r - pos[id]) << '\n';
        }
    }
}
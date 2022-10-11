#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nxt(n, -1);
    for (int i = 0; i < n; i++) {
        cout << '?';
        for (int j = 0; j < n; j++)
            cout << ' ' << 1 + (i == j);

        cout << endl;

        int pos;
        cin >> pos;
        pos--;
        if (pos != -1 && pos < i) {
            assert(nxt[i] == -1);
            nxt[i] = pos;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << '?';
        for (int j = 0; j < n; j++)
            cout << ' ' << 2 - (i == j);

        cout << endl;

        int pos;
        cin >> pos;
        pos--;
        if (pos != -1 && pos < i) {
            assert(nxt[pos] == -1);
            nxt[pos] = i;
        }
    }

    assert(count(all(nxt), -1) == 1);

    vector<bool> good(n, true);
    for (int i = 0; i < n; i++)
        if (nxt[i] != -1)
            good[nxt[i]] = false;

    int c = 0;
    while (!good[c])
        c++;

    vector<int> perm(n);
    for (int i = 1; i <= n; i++, c = nxt[c])
        perm[c] = i;

    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << perm[i] << " \n"[i == n - 1];
}
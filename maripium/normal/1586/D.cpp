#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> prv(N, -1), nxt(N, -1);
    auto link = [&](int x, int y) {
        nxt[x] = y;
        prv[y] = x;
    };
    for (int i = 0; i < N; ++i) {
        cout << "?";
        for (int j = 0; j < N; ++j) {
            cout << ' ' << 1 + (i == j);
        }
        cout << endl;
        int id; cin >> id; --id;
        if (id == -1 || id == i) {
            // do nothing
        } else {
            assert(id < i);
            // A[i] + 1 == A[id]
            link(i, id);
        }
        cout << "?";
        for (int j = 0; j < N; ++j) {
            cout << ' ' << 2 - (i == j);
        }
        cout << endl;
        cin >> id; --id;
        if (id == -1 || id == i) {
            // do nothing
        } else {
            // A[i] == A[id] + 1
            link(id, i);
        }
    }
    int st = 0; while (prv[st] != -1) st++;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[st] = i;
        st = nxt[st];
    }
    cout << "!";
    for (int a : A) cout << ' ' << a+1; cout << endl;
        return 0;
}
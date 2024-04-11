#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int64_t query(int64_t a, int64_t b) {
    cout << "? " << a << ' ' << b << endl;
    int64_t res;
    cin >> res;
    assert(res);
    return res;
}

int main() {
    for (int i = 2 ; ; ++ i) {
        int64_t u = query(1, i);
        if (u == -1) {
            cout << "! " << i - 1<< endl;
            return 0;
        }
        int64_t v = query(i, 1);
        if (u != v) {
            cout << "! " << u + v << endl;
            return 0;
        }
    }
}
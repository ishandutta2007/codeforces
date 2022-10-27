#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

int query(int x, int y) {
    assert(x != y);
    cout << "? " << x << ' ' << y << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;

    int cur = 1;

    for (int nxt = 2 ; nxt <= n ; ++ nxt) {
        int x = query(cur, nxt); /// a[cur] % a[nxt]
        int y = query(nxt, cur); /// a[nxt] % a[cur]

        if (x > y) {
            a[cur] = x;
            cur = nxt;
        } else {
            a[nxt] = y;
        }
    }
    a[cur] = n;

    cout << "! ";
    for (int i = 1 ; i <= n ; ++ i)
        cout << a[i] << ' ';
    cout << endl;
}
/**
    Why 9am tomorrow?
    :sad face
*/
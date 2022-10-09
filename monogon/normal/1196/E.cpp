
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// The most black cells per white cell:

//   #   #   #
// # - # - # - #
//   #   #   #

// b <= 3w + 1.
// w <= 3b + 1.

// We just need to balance off the whites and blacks,
// and make a path with the remaining.

int q, b, w;

void f(int x, int y) {
    cout << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> b >> w;
        int x = 1;
        if(b > 3 * w + 1 || w > 3 * b + 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if(w > b) {
            swap(b, w);
            x = 2;
        }
        // assume b >= w
        if(b > w) {
            f(x, 2);
            b--;
            x++;
        }
        while(b > w) {
            f(x, 2);
            w--;
            f(x + 1, 2);
            f(x, 1);
            b -= 2;
            if(b > w) {
                f(x, 3);
                b--;
            }
            x += 2;
        }
        while(b > 0) {
            f(x, 2);
            f(x + 1, 2);
            b--; w--; x += 2;
        }
    }
}
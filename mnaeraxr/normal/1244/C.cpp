#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, p, w, d;

    cin >> n >> p >> w >> d;

    long long pw = p % w;
    long long dw = d % w;

    for (int y = 0, dy = 0; y < w; ++y, dy += dw) {
        if (dy >= w) dy -= w;

        if (dy == pw) {
            long long x = p - y * d;

            if (x < 0) {
                cout << -1 << endl;
                return 0;
            }

            assert(x % w == 0);
            x /= w;

            if (x + y > n) {
                cout << -1 << endl;
                return 0;
            }

            auto z = n - x - y;

            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}

/*
    p - y * d = 0 (w)

    p = y * d (w)
*/
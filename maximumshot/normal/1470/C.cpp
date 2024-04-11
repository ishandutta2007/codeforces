#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    auto ask = [&](int q) -> ll {
        cout << "? " << q << endl;
        ll res;
        cin >> res;
        return res;
    };

    if (n <= 450) {
        for (int it = 0; it < n + 5; it++)
            ask(1);
        for (int i = 0; i < n; i++) {
            if (ask(i + 1) == k && ask((i + 1) % n + 1) > k) {
                cout << "! " << i + 1 << endl;
                break;
            }
        }
        return 0;
    }
    
    int T = 1;
    while (T * T <= n)
        T++;
    T--;
    for (int it = 0; it < T + 2; it++)
        ask(1);

    int i = -1;

    for (int j = 0; j < n; j += T) {
        if (ask(j + 1) > k) {
            i = j;
            break;
        }
    }

    assert(i != -1);

    int bl = 0, br = n + 1, bm;

    while (br - bl > 1) {
        bm = (bl + br) >> 1;
        int pos = i - bm;
        pos = (pos % n + n) % n;
        if (ask(pos + 1) > k)
            bl = bm;
        else
            br = bm;
    }

    int pos = i - br;
    pos = (pos % n + n) % n;

    cout << "! " << pos + 1 << endl;

    return 0;
}
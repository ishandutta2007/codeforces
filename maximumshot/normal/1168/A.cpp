#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 3e5 + 5;

int n, m;
int a[N];

bool check(int r) {
    int last = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (x <= last) {
            if (x + r < last) return false;
        } else {
            if (x + r < m + last) {
                last = x;
            }
        }
    }
    return true;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int bl = -1;
    int br = m;
    int bm;

    while (br - bl > 1) {
        bm = (bl + br) / 2;
        if (check(bm)) {
            br = bm;
        } else {
            bl = bm;
        }
    }

    cout << br << "\n";

    return 0;
}
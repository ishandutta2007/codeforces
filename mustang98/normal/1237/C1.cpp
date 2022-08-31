#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2011, inf = 1000111222;

int n;
ll x[max_n], y[max_n], z[max_n];
bool used[max_n];

ll sqr(ll a) {
    return a * a;
}

ll dst(int i, int j) {
    return sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i <n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        int a = i;
        used[a] = 1;
        int b = -1;
        for (int j = 0; j < n; ++j) {
            if (used[j]) {
                continue;
            }
            if (b == -1 || dst(a, b) > dst(a, j)) {
                b = j;
            }
        }
        used[b] = 1;
        cout << a + 1 << ' ' << b + 1 << "\n";
    }

    return 0;
}
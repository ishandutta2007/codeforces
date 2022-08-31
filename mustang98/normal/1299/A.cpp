#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_b = 33, inf = 1000111222;

int c[max_b];
ll m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        for (int j = 0; j < max_b; ++j) {
            if (m[i] & (1 << j)) {
                ++c[j];
            }
        }
    }
    int ans = 0;
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        int a = m[i];
        for (int j = 0; j < max_b; ++j) {
            if (m[i] & (1 << j)) {
                --c[j];
            }
        }
        for (int j = 0; j < max_b; ++j) {
            if (c[j]) {
                a |= (1 << j);
                a ^= (1 << j);
            }
        }
        if (a > ans) {
            ans = a;
            pos = i;
        }
        for (int j = 0; j < max_b; ++j) {
            if (m[i] & (1 << j)) {
                ++c[j];
            }
        }
    }
    //cout << ans << endl;
    swap(m[0], m[pos]);
    for (int i = 0; i < n; ++i) {
        cout << m[i] << ' ';
    }
    return 0;
}
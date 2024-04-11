#include <bits/stdc++.h>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4
#define time privet5
#define left privet6

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100011, log_n = 32, max_m = 111, mod = 1000000007, inf = 1011111111;
const ld eps = 1e-7;

int n, k, last;
bool a[55];
string b[55], ans[55];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("substr.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < 26; ++i) {
        b[i] = i + 'A';
    }
    for (int i = 0; i < 26; ++i) {
        b[i + 26] = b[i];
        b[i + 26] += ('a' + i);
    }
    for (int i = k - 1; i < n; ++i) {
        string s;
        cin >> s;
        if (s[0] == 'Y') {
            a[i] = 1;
        }
    }
    for (int i = 0; i < k - 1; ++i) {
        ans[i] = b[i];
    }
    last = k - 1;
    for (int i = k - 1; i < n; ++i) {
        if (a[i]) {
            ans[i] = b[last++];
        } else {
            ans[i] = ans[i - k + 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
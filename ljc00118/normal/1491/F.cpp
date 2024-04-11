#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

int T, n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        int pos = 0;
        for (int i = 2; i <= n; i++) {
            cout << "? " << i - 1 << " " << 1 << endl;
            for (int j = 1; j <= i - 1; j++) cout << j << " ";
            cout << endl;
            cout << i << endl;
            int res; cin >> res;
            if (res) {
                pos = i;
                break;
            }
        }
        int l = 1, r = pos - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            cout << "? " << mid - l + 1 << " " << 1 << endl;
            for (int j = l; j <= mid; j++) cout << j << " ";
            cout << endl;
            cout << pos << endl;
            int res; cin >> res;
            if (res) r = mid;
            else l = mid + 1;
        }
        vector <int> ans;
        for (int i = 1; i < pos; i++) {
            if (i != l) {
                ans.push_back(i);
            }
        }
        for (int i = pos + 1; i <= n; i++) {
            cout << "? 1 1" << endl;
            cout << pos << endl << i << endl;
            int res; cin >> res;
            if (!res) ans.push_back(i);
        }
        cout << "! " << (int)ans.size() << " ";
        for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
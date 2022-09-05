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

const int N = 2005;

vector <int> vec[2];
int d[N], u[N], v[N];
int n, len;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    cout << "? " << 1 << endl;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (i != 1) vec[d[i] & 1].push_back(i);
    }
    int minn = vec[1].size() < vec[0].size();
    if (minn == 0) {
        for (int i = 1; i <= n; i++) {
            if (d[i] == 1) {
                ++len;
                u[len] = 1;
                v[len] = i;
            }
        }
    }
    for (int i = 0; i < (int)vec[minn].size(); i++) {
        int u = vec[minn][i];
        cout << "? " << u << endl;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            if (d[i] == 1) {
                ++len;
                ::u[len] = u;
                v[len] = i;
            }
        }
    }
    cout << "!" << endl;
    assert(len == n - 1);
    for (int i = 1; i <= len; i++) cout << u[i] << " " << v[i] << endl;
    return 0;
}
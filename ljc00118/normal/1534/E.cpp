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

const int N = 505, INF = 0x7f7f7f7f;

queue <int> q;
int dis[N], fr[N], used[N];
int n, k, sum;

int main() {
    memset(dis, 0x7f, sizeof(dis));
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    // n = rand() % 500 + 1; k = rand() % n + 1;
    // cerr << "n = " << n << " " << "k = " << k << endl;
    dis[n] = 0; q.push(n);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i <= u; i++) {
            if (n - u < k - i) continue;
            if (i > k) continue;
            int go = u - i + (k - i);
            if (dis[go] > dis[u] + 1) {
                dis[go] = dis[u] + 1;
                fr[go] = u;
                q.push(go);
            }
        }
    }
    if (dis[0] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vector <int> pos;
    int now = 0;
    while (now != n) {
        int go = fr[now], cnt = (k - (go - now)) / 2, cnt2 = k - cnt;
        vector <int> vec;
        for (int i = 1; i <= n && cnt2; i++) {
            if (!used[i]) {
                used[i] = 1;
                vec.push_back(i);
                --cnt2;
            }
        }
        for (int i = 0; i < cnt; i++) {
            vec.push_back(pos[i]);
            used[pos[i]] = 0;
        }
        cout << "? ";
        for (int i = 0; i < k; i++) cout << vec[i] << " ";
        cout << endl;
        int tem; cin >> tem; sum ^= tem;
        pos.clear();
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                pos.push_back(i);
            }
        }
        now = go;
    }
    cout << "! " << sum << endl;
    return 0;
}
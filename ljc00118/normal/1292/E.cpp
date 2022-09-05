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

const char str[4] = {'!', 'C', 'H', 'O'};
const int N = 55;

int ans[N];
int T, n;

vector <int> query(string x) {
    cout << "? " << x << endl;
    int m; cin >> m; vector <int> ans(m);
    for (int i = 0; i < m; i++) cin >> ans[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while (T--) {
        memset(ans, 0, sizeof(ans));
        read(n);
        auto solve = [&](int a, int b) {
            string qwq; qwq += str[a]; qwq += str[b];
            vector <int> pos = query(qwq);
            for (auto i : pos) {
                ans[i] = a;
                ans[i + 1] = b;
            }
        };
        if (n >= 5) {
            solve(1, 1); solve(1, 2); solve(1, 3); solve(2, 2); solve(3, 2);
            for (int i = 2; i <= n - 1; i++) {
                if (!ans[i]) ans[i] = 3;
            }
            int t1 = ans[1], t2 = ans[n];
            for (int x = 1; x <= 3; x++) {
                if (t1 && x != ans[1]) continue;
                if (!t1 && x == 1) continue;
                for (int y = 1; y <= 3; y++) {
                    if (t2 && y != ans[n]) continue;
                    if (!t2 && y == 2) continue;
                    ans[1] = x; ans[n] = y;
                    if (x == 3 && y == 3) continue;
                    string now(n, '!');
                    for (int i = 0; i < n; i++) now[i] = str[ans[i + 1]];
                    if (query(now).size()) goto ed;
                }
            }
            ed:;
            cout << "! ";
            for (int i = 1; i <= n; i++) cout << str[ans[i]];
            cout << endl;
        } else {
            solve(1, 1); solve(1, 2); solve(1, 3); solve(2, 3);
            int l = 0, r = 0;
            for (int i = 1; i <= n; i++) {
                if (ans[i]) {
                    if (!l) l = i;
                    r = i;
                }
            }
            if (l) {
                while (l > 1) {
                    for (int i = 1; i <= 3; i++) {
                        ans[l - 1] = i;
                        if (i == 3) break;
                        string now(r - l + 2, '!');
                        for (int j = 0; j <= r - l + 1; j++) now[j] = str[ans[l - 1 + j]];
                        vector <int> qwq = query(now);
                        int cando = 0;
                        for (auto j : qwq) if (j == l - 1) cando = 1;
                        if (cando) break;
                    }
                    --l;
                }
                while (r < n) {
                    for (int i = 1; i <= 3; i++) {
                        ans[r + 1] = i;
                        if (i == 3) break;
                        string now(r - l + 2, '!');
                        for (int j = 0; j <= r - l + 1; j++) now[j] = str[ans[l + j]];
                        vector <int> qwq = query(now);
                        int cando = 0;
                        for (auto j : qwq) if (j == l) cando = 1;
                        if (cando) break;
                    }
                    ++r;
                }
                cout << "! ";
                for (int i = 1; i <= n; i++) cout << str[ans[i]];
                cout << endl;
                int qwq; cin >> qwq;
                continue;
            }
            int banH = 0;
            vector <int> res = query("OOO");
            if (res.size() && res[0] == 1) {
                ans[1] = ans[2] = ans[3] = 3;
                goto ed2;
            }
            res = query("OOH");
            if (res.size() && res[0] == 1) {
                ans[1] = ans[2] = 3; ans[3] = 2;
                goto ed2;
            }
            res = query("HHH");
            if (res.size() && res[0] == 1) ans[1] = ans[2] = ans[3] = 2;
            else ans[1] = 3, ans[2] = ans[3] = 2;
            {
                int cando = 0;
                for (auto i : res) {
                    if (i == 2) cando = 1;
                }
                if (cando) ans[4] = 2;
                else banH = 1;
            }
            ed2:;
            if (!ans[4]) {
                for (int i = 1; i <= 3; i++) {
                    if (i == 2 && banH) continue;
                    ans[4] = i;
                    if (i == 3) break;
                    string now(n, '!');
                    for (int j = 0; j < n; j++) now[j] = str[ans[j + 1]];
                    if (query(now).size()) break;
                }
            }
            cout << "! ";
            for (int i = 1; i <= n; i++) cout << str[ans[i]];
            cout << endl;
        }
        int qwq; cin >> qwq;
    }
    return 0;
}
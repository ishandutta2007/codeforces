#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
  
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 1e5 + 5, B = 80;

vector <int> p;
int isp[N], pri[N], vis[N];
int n, len, ans, ANS = 1, flag;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!isp[i]) {
            pri[++len] = i;
            for (int j = i + i; j <= n; j += i) isp[j] = 1;
        }
    }
    ans = n;
    for (int l = 1, r; l <= len; l = r + 1) {
        r = min(l + B - 1, len);
        for (int i = l; i <= r; i++) {
            cout << "B " << pri[i] << endl;
            int tmp, cnt = 0; cin >> tmp;
            for (int j = pri[i]; j <= n; j += pri[i]) {
                if (!vis[j]) {
                    --ans; ++cnt;
                    vis[j] = 1;
                }
            }
            if (flag && cnt != tmp) p.push_back(pri[i]);
        }
        if (flag) continue;
        cout << "A " << 1 << endl;
        int tmp; cin >> tmp;
        if (tmp != ans) {
            flag = 1;
            for (int j = l; j <= r; j++) {
                cout << "A " << pri[j] << endl;
                int res; cin >> res;
                if (res) p.push_back(pri[j]);
            }
        }
    }
    for (int i = 0; i < (int)p.size(); i++) {
        int now = p[i]; ANS *= p[i];
        while (1ll * now * p[i] <= n) {
            now *= p[i];
            cout << "A " << now << endl;
            int res; cin >> res;
            if (res) ANS *= p[i];
            else break;
        }
    }
    cout << "C " << ANS << endl;
    return 0;
}
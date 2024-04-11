// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 5e5 + 5;
 
int n, a[N], b[N], t, ans;

int main() {
    cin >> n;
    while (n--) {
        string s; cin >> s;
        int mn = 0, c = 0;
        for (char v: s) {
            if (v == '(') c++;
            else c--;
            chkMin(mn, c);
        }
        if (c == 0) {
            if (mn >= 0) {
                if (t) ans++, t = 0;
                else t++;
            }
        } else {
            if (c > 0) {
                if (mn >= 0) a[c]++;
            } else {
                if (-c + mn >= 0) {
                    b[-c]++;
                }
            }
        }
    }
    for (int i = 1; i < N; i++) ans += min(a[i], b[i]);
    cout << ans;
    return 0;
}
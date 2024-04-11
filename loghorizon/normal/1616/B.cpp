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
 
int n;

string s, ans;

void inline chk(int k) {
    string t = "";
    for (int i = 0; i < k; i++) t += s[i];
    for (int i = k - 1; i >= 0; i--) t += s[i];
    if (t < ans) ans = t;
}

int main() {
    int T; read(T);
    while (T--) {
        cin >> n;
        cin >> s;
        ans = s;
        for (int i = n - 1; i >= 0; i--) ans += s[i];
        int p = n;
        for (int i = 0; i < n; i++) {
            if (s[i] < s[i + 1]) {
                chk(i + 1);
                p = i;
                break;
            }
        }
        for (int i = 0; i < p; i++) {
            if (s[i] == s[i + 1]) {
                chk(i + 1);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
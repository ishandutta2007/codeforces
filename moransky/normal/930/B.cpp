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

const int N = 5005;

int n, cnt[26];

char s[N];

int st[26];

int inline work(int c, int w) {
    memset(st, 0, sizeof st);
    for (int i = 0; i < n; i++) {
        if (s[i] - 'a' == c) {
            st[s[(i + w) % n] - 'a']++;
        }
    }
    int ct = 0;
    for (int i = 0; i < 26; i++)
        if (st[i] == 1) ct++; 
    return ct;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    int sum = n, cur = 0;
    for (int i = 0; i < 26; i++) {
        int o = 0;
        for (int j = 1; j < n; j++) chkMax(o, work(i, j));
        cur += o;
    }
    double ans = 1.0 * cur / sum;
    printf("%.10lf\n", ans);
    return 0;
}
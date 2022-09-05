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

const int N = 2e5 + 5;

char s[N];
int T, n, a, b, c, d;

int main() {
    read(T);
    while (T--) {
        read(a); read(b); read(c); read(d);
        scanf("%s", s + 1); n = strlen(s + 1);
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'A') ++cnt0;
            if (s[i] == 'B') ++cnt1;
        }
        if (cnt0 != a + c + d || cnt1 != b + c + d) {
            printf("NO\n");
            continue;
        }
        vector <int> vec0, vec1, vec2;
        int cnt = 0, cntt = 0;
        for (int l = 1, r; l < n; l = r + 1) {
            r = l;
            while (r < n && s[r] != s[r + 1]) ++r;
            if ((r - l + 1) % 2 == 0) {
                if (s[l] == 'A') {
                    cnt += (r - l + 1) / 2;
                    vec1.push_back((r - l + 1) / 2);
                } else {
                    cnt += (r - l + 1) / 2 - 1;
                    vec2.push_back((r - l + 1) / 2 - 1);
                }
            } else {
                cnt += (r - l + 1) / 2;
                vec0.push_back((r - l + 1) / 2);
            }
        }
        sort(vec1.begin(), vec1.end()); reverse(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        cnt -= c;
        if (cnt < 0) {
            printf("NO\n");
            continue;
        }
        for (auto i : vec2) {
            if (cnt >= i) {
                cnt -= i;
                cntt += i + 1;
            } else {
                cntt += cnt;
                cnt = 0;
            }
        }
        for (auto i : vec0) {
            int tmp = min(cnt, i);
            cnt -= tmp;
            cntt += tmp;
        }
        for (auto i : vec1) {
            if (cnt >= i) {
                cnt -= i;
                cntt += i - 1;
            } else if (cnt) {
                cntt += (cnt - 1);
                cnt = 0;
            }
        }
        if (cntt >= d) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
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

char c[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n); scanf("%s", c + 1);
        int sum = 0, maxn = 0, pos = 0, cando = 1;
        for (int i = 1; i <= n * 2; i++) {
            if (c[i] == '(') ++sum;
            else --sum;
            if (sum < 0) cando = 0;
            if (sum > maxn) {
                pos = i;
                maxn = sum;
            }
        }
        if (cando) {
            print(0, '\n');
            continue;
        }
        sum = 0; int l = 0, r = n * 2 + 1;
        for (int i = 1; i <= n * 2; i++) {
            if (c[i] == '(') ++sum;
            else --sum;
            if (sum < 0) {
                l = i - 1;
                break;
            }
        }
        sum = 0;
        for (int i = n * 2; i >= 1; i--) {
            if (c[i] == ')') ++sum;
            else --sum;
            if (sum < 0) {
                r = i + 1;
                break;
            }
        }
        sum = maxn = 0;
        int ansl = l + 1, ansr = r - 1;
        for (int i = l; i >= 1; i--) {
            if (c[i] == ')') ++sum;
            else --sum;
            if (sum > maxn) {
                maxn = sum;
                ansl = i;
            }
        }
        sum = maxn = 0;
        for (int i = r; i <= n * 2; i++) {
            if (c[i] == '(') ++sum;
            else --sum;
            if (sum > maxn) {
                maxn = sum;
                ansr = i;
            }
        }
        reverse(c + ansl, c + ansr + 1);
        sum = 0; cando = 1;
        for (int i = 1; i <= n * 2; i++) {
            if (c[i] == '(') ++sum;
            else --sum;
            if (sum < 0) cando = 0;
        }
        if (cando) {
            printf("1\n%d %d\n", ansl, ansr);
            continue;
        }
        printf("2\n%d %d\n%d %d\n", 1, pos, pos + 1, n * 2);
    }
    return 0;
}
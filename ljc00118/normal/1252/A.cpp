#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 16, MAXN = 2000;

priority_queue <pii> pq;
bitset <MAXN + 1> dp[1 << N];
int a[N], b[N];
int n, k, now, cnt, sum;

int main() {
    read(n); read(k);
    for(register int i = 0; i < n; i++) read(a[i]);
    dp[0][0] = 1;
    for(register int i = 0; i < (1 << n); i++) {
        for(register int j = MAXN / k; j >= 1; j--) dp[i][j] = dp[i][j] | dp[i][j * k];
        for(register int j = 0; j < n; j++) if(!((i >> j) & 1)) dp[i ^ (1 << j)] |= dp[i] << a[j];
    }
    if(dp[(1 << n) - 1][1]) { printf("YES\n"); } else { printf("NO\n"); return 0; }
    now = (1 << n) - 1; cnt = 0; sum = 1;
    while(now) {
        if(sum * k <= MAXN && dp[now][sum * k]) { ++cnt; sum *= k; continue; }
        for(register int i = 0; i < n; i++) {
            if(((now >> i) & 1) && sum >= a[i] && dp[now ^ (1 << i)][sum - a[i]]) {
                now ^= (1 << i); b[i] = cnt; sum -= a[i];
                break;
            }
        }
    }
    for(register int i = 0; i < n; i++) pq.push(make_pair(b[i], a[i]));
    while(pq.size() > 1) {
        pii u = pq.top(); pq.pop();
        pii v = pq.top(); pq.pop();
        pii ans = make_pair(u.first, u.second + v.second);
        print(u.second, ' '); print(v.second, '\n');
        while(ans.second % k == 0) {
            ans.second /= k;
            --ans.first;
        }
        pq.push(ans);
    }
    return 0;
}
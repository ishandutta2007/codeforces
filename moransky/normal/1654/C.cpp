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

const int N = 2e5 + 5;

int n, a[N];

int main() {
    int T; read(T);
    while (T--) {
    	read(n);
        LL w = 0;
        multiset<LL> s;
        for (int i = 1; i <= n; i++) read(a[i]), w += a[i], s.insert(a[i]);
        priority_queue<LL> q; q.push(w);
        bool ok = 1;
        for (int i = 1; i < n; i++) {
            while (q.size() && s.find(q.top()) != s.end()) {
                s.erase(s.find(q.top())); q.pop();
            }
            LL o = q.top(); q.pop();
            q.push(o / 2);
            q.push((o + 1) / 2);
        }
        while (q.size() && s.find(q.top()) != s.end()) {
            s.erase(s.find(q.top())); q.pop();
        }
        puts(!s.size() ? "YES" : "NO");
    }
    return 0;
}
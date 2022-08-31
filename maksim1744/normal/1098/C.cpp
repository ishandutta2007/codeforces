/*
    17.03.2019 15:00:02
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    long long n, s;
    cin >> n >> s;
    if (2 * n - 1 > s || n * (n + 1) / 2 < s) {
        cout << "No\n";
        return 0;
    }
    long long l = 0, r = n;
    while (r - l > 1) {
        long long c = (l + r) / 2;
        long long sm = 0;
        long long nn = n;
        long long k = 1;
        long long lvl = 1;
        while (k <= nn) {
            sm += k * lvl;
            nn -= k;
            k *= c;
            ++lvl;
        }
        sm += nn * lvl;
        if (sm <= s)
            r = c;
        else
            l = c;
    }
    // show(r);
    cout << "YES\n";
    vector< int > p(n, -1);
    vector< long long > d(n, 1);
    vector< int > ch(n, 0);
    for (int i = 1; i < n; ++i) {
        p[i] = i - 1;
        d[i] = i + 1;
        ch[i - 1] = 1;
    }
    if (r == 1) {
        for (int i = 1; i < n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
        return 0;
    }
    queue< int > now;
    queue< int > next;
    now.push(0);
    next.push(1);
    long long sm = n * (n + 1) / 2;
    int v = n - 1;
    while (sm != s && v >= 0) {
        long long h = d[v] - (d[now.front()] + 1);
        // shows;
        // show(sm, p, h, now.front());
        // show(sm, s);
        if (h <= sm - s) {
            // show(v, now.front(), h);
            --ch[p[v]];
            next.push(v);
            p[v] = now.front();
            d[v] = d[now.front()] + 1;
            ++ch[now.front()];
            if (ch[now.front()] == r) {
                now.pop();
                if (now.empty()) {
                    swap(now, next);
                    next.push(now.front() + 1);
                }
            }
            sm -= h;
        } else {
            int u = p[v];
            for (int i = 0; i < sm - s; ++i) {
                u = p[u];
            }
            p[v] = u;
            d[v] = d[u] + 1;
            sm = s;
        }
        --v;
    }
    vector< vector< int > > lvls(n);
    for (int i = 0; i < n; ++i) {
        lvls[d[i] - 1].push_back(i);
    }
    vector< int > perm(n);
    vector< int > permi(n);
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        for (auto v : lvls[i]) {
            perm[v] = ind;
            permi[ind] = v;
            ++ind;
        }
    }
    for (int i = 1; i < n; ++i) {
        cout << perm[p[permi[i]]] + 1 << ' ';
    }
    cout << '\n';
    return 0;
}
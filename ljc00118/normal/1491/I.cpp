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

const int N = 6005, INF = 2e9;

int a[N], b[N], c[N], id[N], q[N * 2], s[N], nid[N];
int red[N]; // red[i] = 1 : b[i - 1] > a[i]
int n, pos, wincnt, head, tail; ll ans;

int main() {
    read(n);
    for (int i = 0; i < n; i++) {
        read(a[i]); read(b[i]); read(c[i]);
        id[i] = i;
    }
    if (a[0] > a[1]) swap(id[0], id[1]);
    pos = wincnt = ans = 1;
    while (1) {
        // fprintf(stderr, "id : ");
        // for (int i = 0; i < n; i++) fprintf(stderr, "%d ", id[i]);
        // fprintf(stderr, "\n");
        // fprintf(stderr, "wincnt = %d\n", wincnt);
        // fprintf(stderr, "pos = %d\n", pos);
        if (wincnt == 2) {
            ++ans;
            if (c[id[pos]] > a[id[(pos + 1) % n]]) {
                print(id[pos], ' '); print(ans, '\n');
                return 0;
            }
            pos = (pos + 1) % n; wincnt = 1;
        }
        int cando = 0;
        for (int i = 0; i < n; i++) {
            if (b[id[i]] > a[id[(i + 1) % n]]) {
                red[(i + 1) % n] = 1;
                cando = 1;
            } else {
                red[(i + 1) % n] = 0;
            }
        }
        assert(!red[pos]);
        if (!cando) {
            print(-1, ' '); print(-1, '\n');
            return 0;
        }
        cando = 0;
        for (int i = 0; i < n; i++) {
            if (red[i] && red[(i + 1) % n]) {
                cando = 1;
            }
        }
        if (cando) {
            while (1) {
                ++ans;
                if (wincnt == 1) {
                    if (b[id[pos]] > a[id[(pos + 1) % n]]) {
                        ++wincnt;
                        swap(id[pos], id[(pos + 1) % n]);
                    } else wincnt = 1;
                } else {
                    if (c[id[pos]] > a[id[(pos + 1) % n]]) {
                        print(id[pos], ' '); print(ans, '\n');
                        return 0;
                    }
                    wincnt = 1;
                }
                pos = (pos + 1) % n;
            }
            assert(0);
        }
        if (red[(pos + 1) % n] && b[id[(pos - 1 + n) % n]] < a[id[(pos + 1) % n]]) {
            ++ans;
            swap(id[pos], id[(pos + 1) % n]);
            wincnt = 2;
            pos = (pos + 1) % n;
            continue;
        }
        if (red[(pos + 1) % n] && red[(pos - 1 + n) % n]) {
            while (1) {
                ++ans;
                if (wincnt == 1) {
                    if (b[id[pos]] > a[id[(pos + 1) % n]]) {
                        ++wincnt;
                        swap(id[pos], id[(pos + 1) % n]);
                    } else wincnt = 1;
                } else {
                    if (c[id[pos]] > a[id[(pos + 1) % n]]) {
                        print(id[pos], ' '); print(ans, '\n');
                        return 0;
                    }
                    wincnt = 1;
                }
                pos = (pos + 1) % n;
            }
            assert(0);
        }
        // fprintf(stderr, "ok\n");
        pii gg = make_pair(INF, INF), dred = make_pair(INF, INF); int las = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (red[i]) {
                las = i;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (red[i]) {
                las = i;
            } else {
                if (red[(i + 1) % n]) {
                    if (c[id[i]] > a[id[(i + 2) % n]]) {
                        gg = min(gg, make_pair((n - 1) * ((las - i - 1 + n) % n) + (las - pos + n) % n + 1, id[i]));
                    }
                } else {
                    if (c[id[i]] > a[id[(i + 1) % n]]) {
                        gg = min(gg, make_pair((n - 1) * ((las - i - 1 + n) % n) + (las - pos + n) % n + 1, id[i]));
                    }
                }
            }
        }
        head = 1; tail = 0;
        for (int i = 0; i < n; i++) {
            if (!red[i]) {
                while (head <= tail && b[id[q[tail]]] >= b[id[i]]) --tail;
                q[++tail] = i;
            }
        }
        for (int i = 0; i < n; i++) s[i] = (red[i] ^ 1);
        for (int i = 1; i < n; i++) s[i] += s[i - 1];
        for (int i = 0; i < n; i++) {
            if (!red[i]) {
                while (head <= tail && b[id[q[tail]]] >= b[id[i]]) --tail;
                q[++tail] = i;
            } else if (head <= tail && b[id[q[head]]] < a[id[i]]) {
                while (head < tail && b[id[q[head + 1]]] < a[id[i]]) ++head;
                // fprintf(stderr, "i = %d, q[head] = %d\n", i, q[head]);
                if (q[head] < i) {
                    dred = min(dred, make_pair((i - pos + n) % n + (s[i] - s[q[head]] - 1) * (n - 1), i));
                } else {
                    dred = min(dred, make_pair((i - pos + n) % n + (s[i] + s[n - 1] - s[q[head]] - 1) * (n - 1), i));
                }
            }
        }
        if (gg.first == INF && dred.first == INF) {
            print(-1, ' '); print(-1, '\n');
            return 0;
        }
        if (gg.first <= dred.first) {
            print(gg.second, ' '); print(gg.first + ans, '\n');
            return 0;
        }
        // fprintf(stderr, "dred.first = %d\n", dred.first);
        memset(nid, -1, sizeof(nid));
        vector <int> vec;
        int npos = -1;
        for (int i = 0; i < n; i++) {
            if (red[i]) {
                int dis = (i - pos + n) % n, go, r;
                // fprintf(stderr, "i = %d, i - (dred.first - dis) / (n - 1) - 1 = %d\n", i, i - (dred.first - dis) / (n - 1) - 1);
                if (dis > dred.first) go = i, r = 1;
                else go = (i - (dred.first - dis) / (n - 1) - 1 + n) % n, r = 2 + (dred.first - dis) / (n - 1);
                // fprintf(stderr, "i = %d, go = %d\n", i, go);
                nid[go] = id[i];
                if (i == dred.second) {
                    npos = go;
                    int s;
                    for (int j = i, cnt = 0; ; j = (j - 1 + n) % n) {
                        if (!red[j]) {
                            ++cnt;
                            if (cnt == r) {
                                s = j;
                                break;
                            }
                        }
                    }
                    vec.push_back(id[s]);
                    for (int j = (s + 1) % n; j != s; j = (j + 1) % n) {
                        if (!red[j]) {
                            vec.push_back(id[j]);
                        }
                    }
                }
            }
        }
        for (int i = (npos - 1 + n) % n, j = 0; j < (int)vec.size(); i = (i + 1) % n) {
            if (nid[i] == -1) {
                nid[i] = vec[j];
                ++j;
            }
        }
        memcpy(id, nid, sizeof(id));
        // fprintf(stderr, "dred.first = %d, dred.second = %d\n", dred.first, dred.second);
        ans += dred.first; pos = (npos + 1) % n; wincnt = 2;
    }
    return 0;
}
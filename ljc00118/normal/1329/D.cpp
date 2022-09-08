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

const int N = 2e5 + 5;

struct ele {
    int len, v;
    ele (int a = 0, int b = 0) : len(a), v(b) {}
};

vector <ele> seq;
stack <ele> st;
char c[N];
int cnt[30];
int T, n;

int main() {
    read(T);
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", c + 1); n = strlen(c + 1);
        seq.clear();
        while (!st.empty()) st.pop();
        for (int l = 1, r; l <= n; l = r + 1) {
            r = l;
            while (r < n && c[r] != c[r + 1]) ++r;
            seq.push_back(ele(r - l + 1, c[r] - 'a'));
            ++cnt[c[r] - 'a'];
        }
        int mx = 0, now = (int)seq.size() - 1, len = 0;
        --cnt[seq[now].v];
        for (int i = 0; i < 26; i++) mx = max(mx, cnt[i]);
        if (mx * 2 - 1 <= now) {
            // fprintf(stderr, "case1 : \n");
            print((now + 1) / 2 + 1, '\n');
            for (int i = 0; i < (int)seq.size() - 1; i++) {
                if (st.empty()) {
                    st.push(seq[i]);
                    len += seq[i].len;
                } else {
                    bool ok = (st.top().v != seq[i].v);
                    if (ok) {
                        --cnt[st.top().v]; --cnt[seq[i].v]; now -= 2;
                        mx = 0;
                        for (int j = 0; j < 26; j++) mx = max(mx, cnt[j]);
                        if (mx * 2 - 1 > now) ok = 0, ++cnt[st.top().v], ++cnt[seq[i].v], now += 2;
                    }
                    if (ok) {
                        // fprintf(stderr, "i = %d, len = %d\n", i, len);
                        print(len + 1, ' '); print(len + seq[i].len, '\n');
                        seq[i + 1].len += st.top().len; len -= st.top().len; st.pop();
                    } else {
                        st.push(seq[i]);
                        len += seq[i].len;
                    }
                }
            }
            if (!st.empty()) print(1, ' '), print(st.top().len, '\n'), st.pop();
            print(1, ' '); print(seq[seq.size() - 1].len, '\n');
        } else {
            print(mx + 1, '\n');
            int id = -1;
            for (int i = 0; i < 26; i++) if (mx == cnt[i]) id = i;
            for (int i = 0; i < (int)seq.size() - 1; i++) {
                if (st.empty()) {
                    st.push(seq[i]);
                    len += seq[i].len;
                } else {
                    bool ok = (st.top().v == id) + (seq[i].v == id) == 1;
                    if (ok) {
                        print(len + 1, ' '); print(len + seq[i].len, '\n');
                        seq[i + 1].len += st.top().len; len -= st.top().len; st.pop();
                    } else {
                        st.push(seq[i]);
                        len += seq[i].len;
                    }
                }
            }
            while (!st.empty()) len -= st.top().len, print(len + 1, ' '), print(len + st.top().len, '\n'), st.pop();
            print(1, ' '); print(seq[seq.size() - 1].len, '\n');
        }
    }
    return 0;
}
#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 201111, inf = 1000111222;

int add = 100011;
struct segment_tree{
    char tr[4 * max_n];

    void build(int cur, int l, int r, int stplus) {
        if (l == r) {
            if (l < stplus) {
                tr[cur] = '-';
            } else {
                tr[cur] = '+';
            }
            return;
        }
        int mid = (l + r) / 2;
        build(cur * 2, l, mid, stplus);
        build(cur * 2 + 1, mid + 1, r, stplus);
        tr[cur] = '.';
    }

    void push(int cur, int l, int r) {
        if (l == r) {
            exit(228);
        }
        if (tr[cur] == '.') return;
        if (tr[cur] == 'r') {
            if (tr[cur * 2] == '.') {
                tr[cur * 2] = 'r';
            } else if (tr[cur * 2] == 'r') {
                tr[cur * 2] = '.';
            } else if (tr[cur * 2] == '-') {
                tr[cur * 2] = '+';
            } else {
                tr[cur * 2] = '-';
            }


            if (tr[cur * 2 + 1] == '.') {
                tr[cur * 2 + 1] = 'r';
            } else if (tr[cur * 2 + 1] == 'r') {
                tr[cur * 2 + 1] = '.';
            } else if (tr[cur * 2 + 1] == '-') {
                tr[cur * 2 + 1] = '+';
            } else {
                tr[cur * 2 + 1] = '-';
            }
        }
        if (tr[cur] == '-') {
            tr[cur * 2] = '-';
            tr[cur * 2 + 1] = '-';
        }
        if (tr[cur] == '+') {
            tr[cur * 2] = '+';
            tr[cur * 2 + 1] = '+';
        }
        tr[cur] = '.';
    }

    void push_leaf(int cur, int c) {
        if (c == 'r') {
            if (tr[cur] == '-') {
                tr[cur] = '+';
            } else if (tr[cur] == '+') {
                tr[cur] = '-';
            } else {
                exit(228);
            }
        }
        if (c == '-') {
            tr[cur] = '-';
        }
        if (c == '+') {
            tr[cur] = '+';
        }
    }

    void setv(int cur, int l, int r, int ql, int qr, char c) {
        if (l == ql && r == qr) {
            if (l == r) {
                push_leaf(cur, c);
            } else {
                push(cur, l, r);
                tr[cur] = c;
            }
            return;
        }
        if (qr < l || ql > r) {
            return;
        }
        push(cur, l, r);
        int mid = (l + r) / 2;
        setv(cur * 2, l, mid, ql, min(mid, qr), c);
        setv(cur * 2 + 1, mid + 1, r, max(ql, mid + 1), qr, c);
    }

    char get(int cur, int l, int r, int pos) {
        if (l == r) {
            return tr[cur];
        }
        push(cur, l, r);
        int mid = (l + r) / 2;
        if (pos <= mid) {
            return get(cur * 2, l, mid, pos);
        } else {
            return get(cur * 2 + 1, mid + 1, r, pos);
        }
    }
} st;


void init() {
    st.build(1, 0, max_n - 1, add);
}

void setc(int l, int r, char c) {
    if (l > r) {
        exit(228);
    }
    st.setv(1, 0, max_n - 1, l + add, r + add, c);
}

char getc(int pos) {
    return st.get(1, 0, max_n - 1, pos + add);
}
int m[max_n];

int mx = 100002;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    init();
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
    }
    for (int i = 0; i < q; ++i) {
        char c;
        int x;
        scanf("\n%c %d", &c, &x);
        if (x >= 0 && c == '>') {
            setc(x + 1, mx, '-');
            setc(-mx, - x - 1, '-');
        }
        if (x < 0 && c == '<') {
            setc(-mx, x - 1, '+');
            setc(-x + 1, mx, '+');
        }
        if (x >= 0 && c == '<') {
            setc(x, mx, '+');
            setc(-mx, -x, '+');
            if (x != 0) {
                setc(-x + 1, x - 1, 'r');
            }
        }
        if (x < 0 && c == '>') {
            setc(-mx, x, '-');
            setc(-x, mx, '-');
            setc(x + 1, -x - 1, 'r');
        }
    }
    for (int i = 0; i < n; ++i) {
        char c = getc(m[i]);
        int a = abs(m[i]);
        if (c == '-') {
            a *= -1;
        }
        printf("%d ", a);
    }

    return 0;
}
#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

bool b[max_n];
bool is1[max_n];

struct segment_tree {
    int cb[max_n * 4];
    int c1[max_n * 4];

    void upd(int cur, int l, int r, int pos) {
        if (l == r) {
            cb[cur] = b[l];
            c1[cur] = is1[l];
            if (cb[cur] && c1[cur]) {
                --cb[cur];
                --c1[cur];
            }
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            upd(cur * 2, l, mid, pos);
        } else {
            upd(cur *2 + 1, mid + 1, r, pos);
        }
        int kill = min(c1[cur * 2], cb[cur * 2 + 1]);
        cb[cur] = cb[cur * 2] + cb[cur * 2 + 1] - kill;
        c1[cur] = c1[cur * 2] + c1[cur * 2 + 1] - kill;
    }
} st;

int p[max_n];
int q[max_n];
int n;
int pos[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", p + i);
        --p[i];
        pos[p[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", q + i);
        --q[i];
    }
    int curm = n - 1;

    for (int i  =0; i < n; ++i) {
        while(true) {
            is1[pos[curm]] = 1;
            st.upd(1, 0, n - 1, pos[curm]);
            if (st.c1[1] == 1) {
                break;
            }
            --curm;
        }
        printf("%d ", curm + 1);

        /// add bomb
        b[q[i]] = 1;
        st.upd(1, 0, n - 1, q[i]);
    }
    return 0;
}
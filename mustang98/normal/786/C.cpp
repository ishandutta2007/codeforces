#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back
#define next n1

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;
int m[max_n];

struct segment_tree
{
    int tr[max_n * 4];

    void setv(int cur, int l, int r, int pos, int v) {
        if (l == r) {
            tr[cur] = v;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            setv(cur * 2, l, mid, pos, v);
        } else {
            setv(cur * 2 + 1, mid + 1, r, pos, v);
        }
        tr[cur] = tr[cur * 2] + tr[cur * 2 + 1];
    }

    //rightmost pos where pr sum <= k
    int getL(int cur, int l, int r, int k) {
        if (l == r) {
            if (k == 0) {
                if (tr[cur] == 1) {
                    return l - 1;
                }
                else {
                    return l;
                }
            } else {
                if (tr[cur] == 1) {
                    return l;
                } else {
                    return l + 1;
                }
            }
        }

        int mid = (l + r) / 2;

        if (tr[cur * 2] <= k) {
            return getL(cur * 2 + 1, mid + 1, r, k - tr[cur * 2]);
        } else {
            return getL(cur * 2, l, mid, k);
        }
    }
} st;

int last[max_n];
int next[max_n];
int first[max_n];
int ans[max_n];

int main()
{
   // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        last[i] = -1;
        next[i] = -1;
    }

    set<pair<int, int> > s; //from, k

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        m[i] = a;
        //st.add(1, 0, n - 1, i, m[i]);
        s.insert(mp(0, i + 1));
        if (last[a] == -1) {
            last[a] = i;
            first[a] = i;
        } else {
            next[last[a]] = i;
            last[a] = i;
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (first[i] != -1) {
            st.setv(1, 0, n - 1, first[i], 1);
        }
    }

    int curp = 0;
    int a;
    //cout << st.tr[0] << endl;
    while (!s.empty()) {
        int pos = s.begin()->F;
        int k = s.begin()->S;
        //cout << pos << ' ' << k << endl;
        //cin >> a;
        s.erase(s.begin());
        while (curp < pos) {
            st.setv(1, 0, n - 1, curp, 0);
            if (next[curp] != -1) {
                st.setv(1, 0, n - 1, next[curp], 1);
            }
            curp++;

        }
        int posn = st.getL(1, 0, n - 1, k);
        /*if (k == 1) {
            cout << posn << endl;
        }*/
        ans[k]++;
        if (posn < n - 1) {
            s.insert(mp(posn + 1, k));
        }
    }

    for (int k = 1; k <= n; ++k) {
        printf("%d ", ans[k]);
    }
    return 0;
}
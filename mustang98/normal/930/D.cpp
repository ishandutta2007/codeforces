#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.S < p2.S;
}

struct segment_tree {
    int tree[max_n * 4] = {0};

    void set_v(int v, int l, int r, int pos, int val) {
        if (l == r) {
            tree[v] = val;
            return;
        }
        int mid = (l + r) / 2;

        if (pos <= mid) {
            set_v(v * 2, l, mid, pos, val);
        } else {
            set_v(v * 2 + 1, mid + 1, r, pos, val);
        }

        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }

    int sum(int v, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) {
            return tree[v];
        }

        if (r < ql || l > qr) return 0;

        int mid = (l + r) / 2;

        return sum(v * 2, l, mid, ql, min(qr, mid)) +
               sum(v * 2 + 1, mid + 1, r, max(mid + 1, ql), qr);
    }
};

ll solve(vector<pair<int, int> > pts) {
    sort(pts.begin(), pts.end(), comp);
    vector<pair<int, int> > LR;
    vector<pair<int, int> > BT;
    //////////////////// LR bottom-top
    int curp = 0;
    int L = inf, R = -inf;
    for (int row = 0; row < max_n; ++row) {
        ++L;
        --R;
        while (curp < pts.size() && pts[curp].S == row) {
            L = min(L, pts[curp].F + 1);
            R = max(R, pts[curp].F - 1);
            ++curp;
            //cout << row << ' ' << L << endl;
        }
        if (L > max_n) L = inf;
        if (R < 0) R = -inf;
        LR.PB(MP(L, R));
    }
    /////////////////////// LR top-bottom

    curp = pts.size() - 1;
    L = inf, R = -inf;
    for (int row = max_n - 1; row >= 0; --row) {
        ++L;
        --R;
        while (curp >= 0 && pts[curp].S == row) {
            L = min(L, pts[curp].F + 1);
            R = max(R, pts[curp].F - 1);
            --curp;
        }

        if (L > max_n) L = inf;
        if (R < 0) R = -inf;
        LR[row].F = min(LR[row].F, L);
        LR[row].S = max(LR[row].S, R);
        if (LR[row].F > LR[row].S) {
            LR[row] = MP(inf, -inf);
        }
    }
    //for (int i = 0; i < 4; ++i) {
    //    cout << "I=" << i << " " << LR[i].F << ' ' << LR[i].S << endl;
    //}

    //////////////////// BT left-right
    sort(pts.begin(), pts.end());
    curp = 0;
    int B = inf, T = -inf;
    for (int col = 0; col < max_n; ++col) {
        ++B;
        --T;
        while (curp < pts.size() && pts[curp].F == col) {
            B = min(B, pts[curp].S + 1);
            T = max(T, pts[curp].S - 1);
            ++curp;
        }

        if (B > max_n) B = inf;
        if (T < 0) T = -inf;
        BT.PB(MP(B, T));

    }
    //////////////////// BT right-left
    curp = pts.size() - 1;
    B = inf, T = -inf;
    for (int col = max_n - 1; col >= 0; --col) {
        ++B;
        --T;
        while (curp >= 0 && pts[curp].F == col) {
            B = min(B, pts[curp].S + 1);
            T = max(T, pts[curp].S - 1);
            --curp;
        }
        if (B > max_n) B = inf;
        if (T < 0) T = -inf;
        BT[col].F = min(BT[col].F, B);
        BT[col].S = max(BT[col].S, T);
        if (BT[col].F > BT[col].S) {
            BT[col] = MP(inf, -inf);
        }
    }

    //////////////////////////////////////  /////////////////////////////

    vector<pair<int, int> > start;
    vector<pair<int, int> > finish;
    for (int i = 0; i < max_n; ++i) {
        if (BT[i].F == inf) continue;
        start.PB(MP(i, BT[i].F));
        finish.PB(MP(i, BT[i].S));
    }
    sort(start.begin(), start.end(), comp);
    sort(finish.begin(), finish.end(), comp);
    reverse(start.begin(), start.end());
    reverse(finish.begin(), finish.end());

    ll ans = 0;
    segment_tree st[2];
    for (int row = 0; row < max_n; ++row) {
        while (start.size() && start.back().S == row) {
            st[row % 2].set_v(1, 0, max_n - 1, start.back().F, 1);
            start.pop_back();
        }
        if (LR[row].F != inf) {
            ans += st[row % 2].sum(1, 0, max_n - 1, LR[row].F, LR[row].S);
        }
        while (finish.size() && finish.back().S == row) {
            st[row % 2].set_v(1, 0, max_n - 1, finish.back().F, 0);
            finish.pop_back();
        }
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    vector<pair<int, int> > points1;
    vector<pair<int, int> > points2;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        //--x, --y;
        x += 100000; ///DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDdd
        y += 100000;
        //cout << x << ' ' << y << endl;
        if ((x + y) % 2 == 0) {
            points1.PB(MP(x, y));
        } else {
            points2.PB(MP(x, y));
        }
    }
    ll ans = solve(points1) + solve(points2);
    //cout << solve(points1) << endl;
    //cout << solve(points2) << endl;
    cout << ans;
    return 0;
}
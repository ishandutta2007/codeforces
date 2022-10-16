#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;
const int maxn = 5e5 + 10;

struct point {
    int64 x, y, p;

    bool operator<(const point &o) const {
        return y > o.y;
    }
};

struct st {
    struct node {
        pii value;
        int64 push;
    };

    int n;
    vector<node> data;

    st(vector<int> &pos) : n(pos.size()) {
        data = vector<node>(4 * n);
        build(1, 0, n, pos);
    }

    void build(int p, int b, int e, vector<int> &pos) {
        if (b + 1 == e) {
            data[p].value = pii(-pos[b], pos[b]);
        } else {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            build(l, b, m, pos);
            build(r, m, e, pos);
            data[p].value = max(data[l].value, data[r].value);
        }
    }

    void push(int p, int l, int r){
        if (data[p].push) {
            data[l].value.first += data[p].push;
            data[l].push += data[p].push;
            data[r].value.first += data[p].push;
            data[r].push += data[p].push;
            data[p].push = 0;
        }
    }

    pii query(int p, int b, int e, int x){
        if (b >= x)
            return data[p].value;

        int m = (b + e) >> 1, l = p << 1, r = l | 1;
        push(p, l, r);

        auto ans = query(r, m, e, x);

        if (x < m)
            ans = max(ans, query(l, b, m, x));

        return ans;

    }

    pii query(int64 x){
        // cout << "QUERY: " << x << endl;
        return query(1, 0, n, x);
    }

    void add(int p, int b, int e, int x, int64 v){
        if (b >= x) {
            data[p].value.first += v;
            data[p].push += v;
        } else {
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push(p, l, r);

            add(r, m, e, x, v);

            if (x < m)
                add(l, b, m, x, v);

            data[p].value = max(data[l].value, data[r].value);
        }
    }

    void add(int x, int64 v){
        // cout << "ADD: " << x << " " << v << endl;
        add(1, 0, n, x, v);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<point> pnts;

    vector<int> coords;

    for (int i = 0; i < n; ++i){
        int64 x, y, v;
        cin >> x >> y >> v;

        if (x < y) swap(x, y);

        coords.push_back(x);
        coords.push_back(y);

        pnts.push_back({x, y, v});
    }

    sort(coords.begin(), coords.end());
    auto last = unique(coords.begin(), coords.end());
    coords.resize(last - coords.begin());

    sort(pnts.begin(), pnts.end());

    st S(coords);

    int64 value = 0, ss = 1000000001, en = 1000000001;

    for (int i = 0, j; i < n; i = j){
        for (j = i; j < n && pnts[j].y == pnts[i].y; ++j){
            int x = lower_bound(coords.begin(), coords.end(), pnts[j].x) - coords.begin();
            S.add(x, pnts[j].p);
        }

        int y = lower_bound(coords.begin(), coords.end(), pnts[i].y) - coords.begin();

        pii cur = S.query(y);
        cur.first += pnts[i].y;

        // cout << "RES: " << cur.first << " " << cur.second << endl;

        if (cur.first > value) {
            value = cur.first;
            ss = pnts[i].y;
            en = cur.second;
        }
    }

    cout << value << endl;
    cout << ss << " " << ss << " " << en << " " << en << endl;

    return 0;
}
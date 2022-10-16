#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<int64,bool> answer;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

#define value first
#define valid second

struct rect
{
    int64 p, q, idx;

    int64 eval(int64 x){
        return p * x + q;
    }

    bool operator < (const rect &r) const{
        if (p == r.p) return q < r.q;
        return p < r.p;
    }
};

bool bad(rect a, rect b, rect c){
    return (c.q - a.q) * (b.p - a.p)  >= (b.q - a.q) * (c.p - a.p);
}

void best(answer &a, answer b){
    if (!a.valid) a = b;
    else if (b.valid && a.value < b.value)
        a = b;
}

struct cht{
    int beg;
    vector<rect> ch;

    void insert(rect r){
        while (ch.size() >= 2 && bad(ch[ch.size() - 2], ch.back(), r))
            ch.pop_back();

        while (!ch.empty() && ch.back().p == r.p)
            ch.pop_back();

        ch.push_back(r);
    }

    answer eval(int64 x){
        if (beg == ch.size()) return {0, false};

        while (beg + 1 < ch.size() && ch[beg+1].eval(x) >= ch[beg].eval(x))
            ++beg;

        return {ch[beg].eval(x), true};
    }
};

struct segment_tree{
    int n;
    vector<cht> st;

    segment_tree(int n) : n(n){
        st = vector<cht>(4 * n);
    }

    void update(int p, int b, int e, int x, int y, rect R){
        if (x <= b && e <= y){
            st[p].insert(R);
        }
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            if (x < m) update(l, b, m, x, y, R);
            if (m < y) update(r, m, e, x, y, R);
        }
    }

    answer query(int p, int b, int e, int x, int64 v){
        answer ans = {0, false};

        while (true){
            best(ans, st[p].eval(v));
            if (b + 1 == e) break;

            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            if (x < m) p = l, e = m;
            else p = r, b = m;
        }

        return ans;
    }

    void insert(int x, int y, rect r){
        update(1, 0, n, x, y, r);
    }

    answer eval(int p, int64 x){
        return query(1, 0, n, p, x);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> final(n, n);

    vector<pair<int64,int>> query;
    vector<rect> rlist;

    for (int i = 0; i < n; ++i){
        int m; cin >> m;
        if (m == 1){
            int64 p, q;
            cin >> p >> q;
            rlist.push_back({p, q, i});
        }
        else if (m == 2){
            int p; cin >> p;
            final[p - 1] = i + 1;
        }
        else if (m == 3){
            int64 v; cin >> v;
            query.push_back({v, i});
        }
    }

    sort(rlist.begin(), rlist.end());

    segment_tree st(n);

    for (auto r : rlist){
        st.insert(r.idx, final[r.idx], r);
    }

    sort(query.begin(), query.end());

    vector<pair<int,answer>> ans;

    for (auto q : query){
        answer c_ans = st.eval(q.second, q.first);
        ans.push_back({q.second, c_ans});
    }

    sort(ans.begin(), ans.end());

    for (auto a : ans){
        answer cur = a.second;

        if (!cur.valid) cout << "EMPTY SET" << endl;
        else cout << cur.value << endl;
    }

    return 0;
}
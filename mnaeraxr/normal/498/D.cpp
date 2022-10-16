#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct segment_tree{
    int D[4 * maxn][60];

    void merge(int p, int l, int r){
        for (int i = 0; i < 60; ++i)
            D[p][i] = D[l][i] + D[r][ (i + D[l][i]) % 60];
    }

    void build(int p, int b, int e, vi &v){
        if (b + 1 == e){
            for (int i = 0; i < 60; ++i)
                D[p][i] = 1 + (i % v[b] == 0);
        }
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            build(l, b, m, v);
            build(r, m, e, v);

            merge(p, l, r);
        }
    }

    void update(int p, int b, int e, int x, int v){
        if (b + 1 == e){
            for (int i = 0; i < 60; ++i)
                D[p][i] = 1 + (i % v == 0);
        }
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            if (x < m) update(l, b, m, x, v);
            else update(r, m, e, x, v);

            merge(p, l, r);
        }
    }

    int query(int p, int b, int e, int x, int y, int t){
        if (x <= b && e <= y) return t + D[p][t % 60];
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            if (x < m) t = query(l, b, m, x, y, t);
            if (m < y) t = query(r, m, e, x, y, t);
            return t;
        }
    }
} ST;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> value(n);

    for (int i = 0; i < n; ++i)
        cin >> value[i];

    ST.build(1, 0, n, value);

    int q; cin >> q;

    while (q--){
        string s;
        int a, b;
        cin >> s >> a >> b;

        if (s == "A"){
            cout << ST.query(1, 0, n, a - 1, b - 1, 0) << endl;
        }
        else{
            ST.update(1, 0, n, a - 1, b);
        }
    }

    return 0;
}
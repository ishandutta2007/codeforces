#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct segment_tree{
    int64 sum[4 * maxn];
    int64 mx[4 * maxn];

    void build(int p, int b, int e, vi &v){
        if (b + 1 == e) mx[p] = sum[p] = v[b];
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            build(l, b, m, v);
            build(r, m, e, v);

            sum[p] = sum[l] + sum[r];
            mx[p] = max(mx[l], mx[r]);
        }
    }

    void change(int p, int b, int e, int x, int64 v){
        if (b + 1 == e) mx[p] = sum[p] = v;
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            if (x < m) change(l, b, m, x, v);
            else change(r, m, e, x, v);

            sum[p] = sum[l] + sum[r];
            mx[p] = max(mx[l], mx[r]);

        }
    }

    bool update(int p, int b, int e, int x, int y, int64 mod){
        if (mx[p] < mod) return false;

        if (b + 1 == e){
            mx[p] = sum[p] = sum[p] % mod;
            return true;
        }

        int m = (b + e) >> 1, l = p << 1, r = l | 1;

        if (x <= b && e <= y){
            if (mx[l] >= mod) update(l, b, m, x, y, mod);
            else update(r, m, e, x, y, mod);

            sum[p] = sum[l] + sum[r];
            mx[p] = max(mx[l], mx[r]);

            return true;
        }

        if (x < m){
            if (update(l, b, m, x, y, mod)){
                sum[p] = sum[l] + sum[r];
                mx[p] = max(mx[l], mx[r]);
                return true;
            }
        }

        if (m < y){
            if (update(r, m, e, x, y, mod)){
                sum[p] = sum[l] + sum[r];
                mx[p] = max(mx[l], mx[r]);
                return true;
            }
        }

        return false;
    }

    int64 query(int p, int b, int e, int x, int y){
        if (x <= b && e <= y) return sum[p];
        else{

            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            int64 answer = 0;
            if (x < m) answer += query(l, b, m, x, y);
            if (m < y) answer += query(r, m, e, x, y);

            return answer;
        }
    }
} ST;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vi V(n);

    for (int i = 0; i < n; ++i){
        cin >> V[i];
    }

    ST.build(1, 0, n, V);

    while (q--){
        int t; cin >> t;

        if (t == 1){
            int l, r;
            cin >> l >> r;

            cout << ST.query(1, 0, n, l - 1, r) << endl;
        }
        else if (t == 2){
            int l, r;
            int64 x;
            cin >> l >> r >> x;

            while (ST.update(1, 0, n, l - 1, r, x));
        }
        else{
            int k; int64 x;
            cin >> k >> x;
            ST.change(1, 0, n, k - 1, x);
        }
    }

    return 0;
}
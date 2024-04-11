#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct segment_tree{
    vector<int> data, lazy;

    segment_tree(vector<int> &value){
        int n = (int)value.size();
        data = vi(4 * n);
        lazy = vi(4 * n);

        build(1, 0, n, value);
    }

    void build(int p, int b, int e, vector<int> &value){
        if (b + 1 == e)
            data[p] = value[b];
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            build(l, b, m, value);
            build(r, m, e, value);
            data[p] = max( data[l], data[r] );
        }
    }

    void push(int p, int l, int r){
        if (lazy[p]){
            lazy[l] += lazy[p];
            data[l] += lazy[p];
            lazy[r] += lazy[p];
            data[r] += lazy[p];
            lazy[p] = 0;
        }
    }

    void update(int p, int b, int e, int x, int y, int v){
        if (x <= b && e <= y){
            lazy[p] += v;
            data[p] += v;
        }
        else{
            int m = (b + e) >> 1, l = p << 1, r = l | 1;
            push(p, l, r);
            if (x < m) update(l, b, m, x, y, v);
            if (m < y) update(r, m, e, x, y, v);
            data[p] = max(data[l], data[r]);
        }
    }

    int query(int p, int b, int e, int x, int y){
        if (x <= b && e <= y) return data[p];
        int m = (b + e) >> 1, l = p << 1, r = l | 1;
        push(p, l, r);

        int answer = 0;
        if (x < m) answer = max(answer, query(l, b, m, x, y));
        if (m < y) answer = max(answer, query(r, m, e, x, y));

        return answer;
    }
};

int value[ maxn ];
int last[ maxn ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    map<int,int> _last;

    for (int i = 1; i <= n; ++i){
        cin >> value[i];
        last[i] = _last[ value[i] ];
        _last[ value[i] ] = i;
    }

    vector<int> dp(n+1,-oo);
    dp[0] = 0;
    int N = n + 1;

    for (int t = 1; t <= k; ++t){
        for (int i = n; i; --i)
            dp[i] = dp[i-1];

        segment_tree st(dp);

        for (int i = 1; i <= n; ++i){
            st.update(1, 0, N, last[i]+1,i+1, +1);
            dp[i] = st.query(1,0,N,1,i+1);
        }
    }

    cout << dp.back() << endl;

    return 0;
}
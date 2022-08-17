#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2000111, inf = 1000111222;

int a[max_n];
int b[max_n];
int n, m;
vector<int> ccc;
void clr() {
    ccc.clear();
    //cout << "AAA" << endl;
}

int get_small(int large) {
    return lower_bound(ccc.begin(), ccc.end(), large) - ccc.begin();
}


struct segment_tree {
    int sum[max_n * 4];
    int mn[max_n * 4];
    void build(int cur, int l, int r) {
        if (l == r) {
            mn[cur] = 0;
            sum[cur] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(cur * 2, l, mid);
        build(cur * 2 + 1, mid + 1, r);
        sum[cur] = sum[cur * 2] + sum[cur * 2 + 1];
        mn[cur] = min(mn[cur * 2], sum[cur * 2] +mn[cur * 2 + 1]);
    }

    void upd(int cur, int l, int r, int pos, int val) {
        if (l == r) {
            sum[cur] = val;
            if (val < 0) mn[cur] = val;
            else mn[cur] = 0;
            return;
        }
        int mid = (l  + r) / 2;
        if (pos <= mid) {
            upd(cur * 2, l, mid, pos, val);
        } else {
            upd(cur * 2 + 1, mid + 1, r, pos, val);
        }
        sum[cur] = sum[cur * 2] + sum[cur * 2 + 1];
        mn[cur] = min(mn[cur * 2], sum[cur * 2] + mn[cur * 2 + 1]);
    }
} st;

int ft[2 * max_n];

void add(int pos, int val) {
    for (int i = pos; i < n + m; i |= (i + 1)) {
        ft[i] += val;
    }
}

int get(int pos) {
    int ans = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        ans += ft[i];
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        clr();
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ccc.PB(a[i]);
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            ccc.PB(b[i]);
        }
        st.build(1, 0, n + m - 1);
        sort(ccc.begin(), ccc.end());
        ccc.erase(unique(ccc.begin(), ccc.end()), ccc.end());
        vector<pair<int, int>> v;
        for (int i = 0; i <  n + m; ++i) {
            ft[i] = 0;
        }
        ll ans2 = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = get_small(a[i]);
            ans2 += (i - get(a[i]));
            add(a[i], 1);
            v.emplace_back(a[i], i);

        }
        for (int i = 0; i < m; ++i) {
            b[i] = get_small(b[i]);
        }
        //cout << "########## " << ans2 << endl;
        ll ans = 0;
        sort(b, b + m);
        int cnt_less = 0;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector<pair<int, int>> v2;
        for (int i = 0; i < m; ++i) {
            int cur = b[i];
            while(!v2.empty() && v2.back().F < cur) {
                //cout << "%- " << v2.back().S << ' ' << endl;
                st.upd(1, 0,  n + m - 1, v2.back().S, -1);
                v2.pop_back();
                ++cnt_less;
            }
            while(!v.empty() && v.back().F < cur) {
                //cout << "%- " << v.back().S << ' ' << endl;
                st.upd(1, 0,  n + m - 1, v.back().S, -1);
                v.pop_back();

                ++cnt_less;
            }
            while(!v.empty() && v.back().F == cur) {
                //cout << "%0 " << v.back().S << ' ' << endl;
                st.upd(1, 0,  n + m - 1, v.back().S, 0);
                v2.push_back(v.back());
                v.pop_back();
            }
            //cout << "$ " << cnt_less << ' ' << st.mn[1] << endl;
            ans += cnt_less + st.mn[1];
        }
        cout << ans2 + ans << "\n";

    }

    return 0;
}
#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

struct Queue {
    vector< pii > L, R;
    void push(int x) {
        int y = R.empty() ? x : max(x, R.back().second);
        R.push_back({x, y});
    }
    void upd() {
        while(!R.empty()) {
            int x = R.back().first;
            int y = L.empty() ? x : max(L.back().second, x);
            L.push_back({x, y});
            R.pop_back();
        }
    }
    void pop() {
        if(L.empty()) {
            upd();
        }
        assert(!L.empty());
        L.pop_back();
    }
    int get() {
        return max(L.empty() ? -inf : L.back().second, R.empty() ? -inf : R.back().second);
    }
    bool empty() {
        return L.empty() && R.empty();
    }
};

const int N = 1505;

int n, s, m, k;
int a[N];
int b[N];
vector< pii > segs;
vector< int > prv;

inline void upd(int &x, int y) {
    if(x < y) x = y;
}

bool check(int x) {
    for(int i = 1;i <= n;i++) {
        b[i] = b[i - 1] + (a[i] <= x);
    }
    auto get = [&](int l, int r) -> int {
        if(l > r) return 0;
        return b[r] - b[l - 1];
    };
    vector< vector< int > > dp(s, vector< int >(s + 1));
//    for(int i = 0;i < s;i++) {
//        for(int c = 1;c <= i + 1;c++) {
//            if(c == 1) {
//                dp[i][c] = get(segs[i].first, segs[i].second);
//                continue;
//            }
//            for(int j = 0;j <= prv[i];j++) {
//                upd(dp[i][c], dp[j][c - 1] + get(segs[i].first, segs[i].second));
//            }
//            for(int j = prv[i] + 1;j < i;j++) {
//                upd(dp[i][c], dp[j][c - 1] + b[ segs[i].second ] - b[ segs[j].second ]);
//            }
//        }
//    }
    for(int i = 0;i < s;i++) {
        dp[i][1] = get(segs[i].first, segs[i].second);
    }
    for(int c = 2;c <= s;c++) {
//        multiset< int > pr, sf;
        Queue pr, sf;
        for(int j = -1, i = 0;i < s;i++) {
            while(j + 1 < i && segs[j + 1].second < segs[i].first) {
//                pr.insert(dp[j + 1][c - 1]);
                pr.push(dp[j + 1][c - 1]);
//                sf.erase(sf.lower_bound(dp[j + 1][c - 1] - b[ segs[j + 1].second ]));
                sf.pop();
                j++;
            }
            if(!pr.empty()) {
                dp[i][c] = max(dp[i][c], pr.get() + get(segs[i].first, segs[i].second));
            }
            if(!sf.empty()) {
                dp[i][c] = max(dp[i][c], sf.get() + b[segs[i].second]);
            }
//            sf.insert(dp[i][c - 1] - b[ segs[i].second ]);
            sf.push(dp[i][c - 1] - b[segs[i].second]);
        }
    }
//    for(pii p : segs) {
//        cout << p.first << " .. " << p.second << "\n";
//    }
    for(int i = 0;i < s;i++) {
        for(int c = 1;c <= m && c <= s;c++) {
            if(dp[i][c] >= k) return 1;
        }
    }
    return 0;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m >> k;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    for(int i = 0;i < s;i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    {
        sort(segs.begin(), segs.end());
        segs.resize(unique(segs.begin(), segs.end()) - segs.begin());
        vector< pii > hlp;
        for(int i = 0;i < (int)segs.size();i++) {
            int ok = 1;
            for(int j = 0;j < (int)segs.size();j++) {
                if(i == j) continue;
                if(segs[j].first <= segs[i].first && segs[i].second <= segs[j].second) {
                    ok = 0;
                    break;
                }
            }
            if(ok) hlp.push_back(segs[i]);
        }
        segs = hlp;
        sort(segs.begin(), segs.end());
        s = (int)segs.size();
    }

//    cout << "s = " << s << "\n";

    prv.resize(s, -1);

    for(int i = 0;i < s;i++) {
        prv[i] = i;
        while(prv[i] >= 0 && segs[ prv[i] ].second >= segs[i].first) prv[i]--;
    }

//    check(2);
//    return 0;
    int bl = 0;
    int br = inf + 1;
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    cout << (br == inf + 1 ? -1 : br) << "\n";

    return 0;
}
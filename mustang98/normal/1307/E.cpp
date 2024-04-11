#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 5011, inf = 1000111222, mod = 1000000007;

vector<int> cpos[max_n];
int n, m;
int col[max_n];
int h[max_n];
int dl[max_n];
int dr[max_n];
//vector<int> drc[max_n];
vector<int> cc[max_n];

// cnt, ways
pair<ll, ll> solve(int st) {
    if (dl[st] == inf) {
        return MP(0, 0);
    }
    int mxl = dl[st];
    int mxr = (n - mxl - 2);
    //cout << "$" << mxl << ' ' << mxr << endl;
    int stc = col[st];
    ll cnt = 1, ways = 0;
    if (cc[stc].size() >= 2) {
        for (int i : cc[stc]) {
            if (i == st) {
                continue;
            }
            if (dr[i] <= mxr) {
                cnt = 2;
                ++ways;
            }
        }
    }
    if (cnt == 1) {
        ways = 1;
    }
    for (int curc = 0; curc <= n; ++curc) {
        if (curc == stc) {
            continue;
        }
        if (cc[curc].size() == 0) {
            continue;
        }
        ll ways2 = 0;
        int cfitr = 0;
        for (int i : cc[curc]) {
            if (dr[i] <= mxr) {
                ++cfitr;
            }
        }
        for (int l : cc[curc]) {
            if (dl[l] > mxl) {
                continue;
            }
            if (dr[l] <= mxr) {
                ways2 += (cfitr - 1);
            } else {
                ways2 += cfitr;
            }
        }
        if (ways2 > 0) {
            cnt += 2;
            ways = (1LL * ways * ways2) % mod;
            continue;
        }
        ll ways1 = 0;
        for (int i : cc[curc]) {
            if (dl[i] <= mxl) {
                ++ways1;
            }
            if (dr[i] <= mxr) {
                ++ways1;
            }
        }
        if (ways1 > 0) {
            cnt++;
            ways = (1LL * ways * ways1) % mod;
            continue;
        }
    }
    return MP(cnt, ways);
}



// cnt, ways
pair<ll, ll> solve_allr() {
    ll cnt = 0, ways = 1;
    for (int curc = 0; curc <= n; ++curc) {
        int ways1 = 0;
        for (int r : cc[curc]) {
            if (dr[r] != inf) {
                ++ways1;
            }
        }
        if (ways1 > 0) {
            ++cnt;
            ways = (1LL * ways * ways1) % mod;
        }
    }
    return MP(cnt, ways);
}


int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cpos[a].PB(i);
    }
    for (int i = 0; i < m; ++i) {
        cin >> col[i] >> h[i];
        cc[col[i]].PB(i);
        if (h[i] > cpos[col[i]].size()) {
            dl[i] = inf;
            dr[i] = inf;
        } else {
            dl[i] = cpos[col[i]][h[i] - 1];
            dr[i] = cpos[col[i]][cpos[col[i]].size() - h[i]];
            dr[i] = n - 1 - dr[i];
        }
        //cout << "$" << dl[i] << ' ' << dr[i] << endl;
    }
    ll max_c = 0;
    ll cnt = 0;
    for (int i = 0; i < m; ++i) {
        pair<ll, ll> res = solve(i);
        //cout << res.F << ' ' << res.S << endl;
        if (res.F < max_c) {
            continue;
        }
        if (res.F == max_c) {
            cnt += res.S;
            cnt %= mod;
            continue;
        }
        if (res.F > max_c) {
            max_c = res.F;
            cnt = res.S;
        }
    }
    pair<ll, ll> res = solve_allr();
    //cout << res.F << ' ' << res.S << endl;
    if (res.F == max_c) {
        cnt += res.S;
        cnt %= mod;
    } else if (res.F > max_c) {
        max_c = res.F;
        cnt = res.S;
    }
    if (max_c == 0) {
        cnt = 1;
    }
    cout << max_c << ' ' << cnt << endl;
    return 0;
}
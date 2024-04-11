
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    P rob[2000], sl[2000];
    rep(i, n) cin >> rob[i].first >> rob[i].second;
    rep(i, m) cin >> sl[i].first >> sl[i].second;
    sort(sl, sl + m);

    bool valid[2000];
    rep(i, m) valid[i] = true;
    rep(i, m) {
        int j = i-1;
        while(j >= 0 && sl[j].second <= sl[i].second && valid[j]) {
            valid[j] = false;
            j--;
        }
    }
    map<int, int> b;
    rep(i, m) if (valid[i]) b[sl[i].first] = sl[i].second;

    map<int, int> rm[2000];
    vector<int> xevents{0};
    xevents.reserve(n);
    rep(i, n) {
        auto& t = rm[i];
        int x = rob[i].first, y = rob[i].second;
        int prev = x;
        for(auto it = b.lower_bound(x); it != b.end(); it++) {
            if (it->second >= y) {
                t[prev - x] = it->second - y + 1;
                xevents.push_back(prev - x);
                prev = it->first + 1;
            } else break;
        }
        t[prev-x] = 0;
        xevents.push_back(prev - x);
    }
    sort(all(xevents));
    xevents.erase(unique(all(xevents)), xevents.end());
    /*for(auto& t: rm) {
        for(auto p: t) {
            cout << p.first << ' ' << p.second << endl;
        }
        cout << endl;
    }
    for(auto p: b) {
        cout << p.first << ' ' << p.second << endl;
    }*/
    int ans = 1001001001;
    decltype(rm[0].begin()) it[2000];
    rep(i, n) it[i] = rm[i].begin();
    for(int dx: xevents) {
        //cout << "xx" << dx << endl;
        int dy = 0;
        rep(i, n) {
            auto& t = it[i];
            if (t == rm[i].end()) continue;
            while(1) {
                //cout << "zzz" << t->first << ' ' << dx << endl;
                auto it2 = t;
                it2++;
                if (it2 == rm[i].end()) break;
                if (it2->first <= dx) t = it2;
                else break;
            }/*
                auto it2 = t;
                it2++;
                if (it2 == rm[i].end()) break;
                if (it2->first < dx) t = it2;
                else break;
            }*/
            if (t != rm[i].end()) {
                int ty = t->second;
        //    if (dx == 2) cout << "aaaa" << ty << endl;
                chmax(dy, ty);
                //cout << dx << ' ' << ty << endl;
            }
        }
        //if (dx == 2) cout << "zz" << dy << endl;
        chmin(ans, dx + dy);
    }
    cout << ans << endl;
}
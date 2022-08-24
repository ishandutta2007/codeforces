#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    ld x, y;
    cin >> x >> y;
    int where = -1;
    for (int den = 1; den <= 4 * n * n; den++) {
        ld p = x * den;
        ld q = y * den;
        if (abs(p - round(p)) < 1e-6 && abs(q - round(q)) < 1e-6) {
            where = den;
            break;
        }
    }
    assert(where != -1);
    int P = round(where * x);
    int Q = round(where * y);
    int D = n / 2;
    map<pair<int,pair<ll,ll>>, int> mp;

    for (int mask = 0; mask < (1 << D); mask++) {
        vector<pair<int,int>> pts;
        bool ok = true;
        int x = 0;
        int y = 0;
        pts.emplace_back(x, y);
        for (int i = 0; i < D; i++) {
            x += 1;
            if (mask & (1 << i)) {
                y++;
            }
            else {
                y--;
            }
            if (y < 0) {
                ok = false;
                break;
            }
            pts.emplace_back(x, y);
        }
        if (!ok) continue;
        ll sX = 0;
        ll sY = 0;
        ll S = 0;
        for (int t = 0; t + 1 < pts.size(); t++) {
            int x1 = pts[t].first;
            int y1 = pts[t].second;
            int x2 = pts[t + 1].first;
            int y2 = pts[t + 1].second;
            ll nS = 3 * (y1 + y1);
            ll nX = 3 * y1 * (x1 + x2);
            ll nY = 3 * y1 * y1;
            if (y2 > y1) {
                nS += 3;
                nX += (x1 + x2 + x2);
                nY += (y1 + y1 + y2);
            }
            else {
                nS -= 3;
                nX -= (x1 + x2 + x2);
                nY -= (y1 + y1 + y2);
            }
            sX += nX;
            sY += nY;
            S += nS;
        }
        mp[make_pair(pts.back().second, make_pair(S * P - where * sX, S * Q - where * sY))] = mask;
    }
    for (int mask = 0; mask < (1 << D); mask++) {
        vector<pair<int,int>> pts;
        bool ok = true;
        int x = n;
        int y = 0;
        pts.emplace_back(x, y);
        for (int i = 0; i < D; i++) {
            x -= 1;
            if (mask & (1 << i)) {
                y++;
            }
            else {
                y--;
            }
            if (y < 0) {
                ok = false;
                break;
            }
            pts.emplace_back(x, y);
        }
        if (!ok) continue;
        reverse(pts.begin(), pts.end());
        ll sX = 0;
        ll sY = 0;
        ll S = 0;
//        for (auto& it : pts) cout << it.first << " " << it.second << endl;
        for (int t = 0; t + 1 < pts.size(); t++) {
            int x1 = pts[t].first;
            int y1 = pts[t].second;
            int x2 = pts[t + 1].first;
            int y2 = pts[t + 1].second;
            ll nS = 3 * (y1 + y1);
            ll nX = 3 * y1 * (x1 + x2);
            ll nY = 3 * y1 * y1;
            if (y2 > y1) {
                nS += 3;
                nX += (x1 + x2 + x2);
                nY += (y1 + y1 + y2);
            }
            else {
                nS -= 3;
                nX -= (x1 + x2 + x2);
                nY -= (y1 + y1 + y2);
            }
            sX += nX;
            sY += nY;
            S += nS;
        }
        if (mp.count(make_pair(pts[0].second, make_pair(-(S * P - where * sX), -(S * Q - where * sY))))) {
            int his_mask = mp[make_pair(pts[0].second, make_pair(-(S * P - where * sX), -(S * Q - where * sY)))];
            string s;
            for (int i = 0; i < D; i++) {
                if (his_mask & (1 << i)) {
                    s += '(';
                }
                else {
                    s += ')';
                }
            }
            for (int t = 0; t + 1 < pts.size(); t++) {
                if (pts[t + 1].second == pts[t].second + 1) s += '(';
                else s += ')';
            }
            cout << s;
            return 0;
        }
    }

    return 0;
}
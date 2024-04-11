#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 5 * (int)1e4 + 10;
int n, m;
vector < pair < int, pair < int, int > > > vert, hor;
const int maxK = 4 * maxN;
int fenw[maxK + 10];
const int ASK = 0;
const int ADD = 1;
const int DEL = 2;
void upd(int v, int d) {
    while (v <= maxK) {
        fenw[v] += d;
        v = (v | (v - 1)) + 1;
    }
}
int sum(int r) {
    if (r < 0) return 0;
    int ans = 0;
    while (r > 0) {
        ans += fenw[r];
        r = (r & (r - 1));
    }
    return ans;
}
int get(int l, int r) {
    return sum(r) - sum(l - 1);
}
bool ok(vector < pair < int, pair < int, int > > >& new_vert, vector < pair < int, pair < int, int > > >& new_hor) {
    if (new_vert.empty() || new_hor.empty()) return false;
    map < int, int > by_x = {};
    map < int, int > by_y = {};
    for (auto t : new_vert) {
        by_x[t.first] = -1;
        by_y[t.second.first] = -1;
        by_y[t.second.second] = -1;
    }
    for (auto t : new_hor) {
        by_y[t.first] = -1;
        by_x[t.second.first] = -1;
        by_x[t.second.second] = -1;
    }
    int szX = 2, szY = 2;
    for (auto& it : by_x) {
        it.second = szX;
        szX++;
    }
    for (auto& it : by_y) {
        it.second = szY;
        szY++;
    }
    // y_1 a += 1
    vector < pair < int, pair < int, int > > > events[szX + 10];
    for (auto& it : new_vert) {
        it = make_pair(by_x[it.first], make_pair(by_y[it.second.first], by_y[it.second.second]));
       // cout << "eventx " << endl;
       // cout << it.first << " " << it.second.first << " " << it.second.second << endl;
        events[it.first].emplace_back(make_pair(ASK, it.second));
    }
    for (auto& it : new_hor) {
        it = make_pair(by_y[it.first], make_pair(by_x[it.second.first], by_x[it.second.second]));
        events[it.second.first - 1].push_back(make_pair(ADD, make_pair(it.first, -1)));
        events[it.second.second].push_back(make_pair(DEL, make_pair(it.first, -1)));
    }
    memset(fenw, 0, sizeof fenw);
    for (int i = 1; i <= szX; i++) {
        for (auto t : events[i]) {
            if (t.first == ASK) {
                if (get(t.second.first, t.second.second) > 0) return true;
            }
            else if (t.first == ADD) {
                upd(t.second.first, 1);
            }
            else {
                upd(t.second.first, -1);
            }
        }
    }
    return false;
}
bool check(int val) {
    vector < pair < int, pair < int, int > > > new_vert, new_hor;
    for (auto t : vert) {
       // cout << t.first << " " << t.second.first << " " << t.second.second << " Ok1" << endl;
        if (t.second.second - t.second.first < 2 * val) continue;
        new_vert.emplace_back(t.first, make_pair(t.second.first + val, t.second.second - val));
       // cout << t.first << " " << " " << t.second.first + val << " " << t.second.second - val << endl;
    }
    for (auto t : hor) {
        if (t.second.second - t.second.first < 2 * val) continue;

       // cout << t.first << " " << t.second.first << " " << t.second.second << " Ok2" << endl;
       // cout << t.first << " " << " " << t.second.first + val << " " << t.second.second - val << endl;
        new_hor.emplace_back(t.first, make_pair(t.second.first + val, t.second.second - val));
    }
    return ok(new_vert, new_hor);
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x1, y1, l1;
        cin >> x1 >> y1 >> l1;
        vert.push_back(make_pair(x1, make_pair(y1, y1 + l1)));
    }
    for (int i = 1; i <= m; i++) {
        int x2, y2, l2;
        cin >> x2 >> y2 >> l2;
        hor.push_back(make_pair(y2, make_pair(x2, x2 + l2)));
    }
    int l = 0;
    int r = (int)1e9;
    //check(2);
    //return 0;
    if (!check(l)) {
        cout << 0;
    }
    else {
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid)) l = mid;
            else r = mid;
        }
        cout << l;
    }
    return 0;
}
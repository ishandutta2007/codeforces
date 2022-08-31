#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
struct pt{
    ll x, y;
    pt() : x(0), y(0) {}
    pt(ll _x, ll _y) : x(_x), y(_y) {}
    pt operator +(pt other) {
        return {x + other.x, y + other.y};
    }
    pt operator -(pt other) {
        return {x - other.x, y - other.y};
    }
    // x / y > other.x / other.y
};
ll operator *(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}
bool cmp(pt& a, pt& b) {
    return ((a.x < b.x) || (a.x == b.x && a.y < b.y));
}
int n;
ll S;
void convex_hull(vector < pt >& all) {
    sort(all.begin(), all.end(), cmp);
    if (all.size() == 1) return ;
    vector < pt > up, down;
    pt p1 = all[0];
    pt p2 = all.back();
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < all.size(); i++) {
        if (i == all.size() - 1) {
            up.push_back(all[i]);
            down.push_back(all[i]);
        }
        else {
            if (((all[i] - p1) * (p2 - p1)) > 0) {
                while (down.size() >= 2 && (((all[i] - down[down.size() - 2]) * (down.back() - down[down.size() - 2])) >= 0)) {
                    down.pop_back();
                }
                down.push_back(all[i]);
            }
            else if ((all[i] - p1) * (p2 - p1) < 0) {
                while (up.size() >= 2 && (((all[i] - up[up.size() - 2])) * (up.back() - up[up.size() - 2])) <= 0) {
                    up.pop_back();
                }
                up.push_back(all[i]);
            }
        }
    }
    all.clear();
    for (int i = 0; i < up.size(); i++) all.push_back(up[i]);
    for (int i = down.size() - 2; i >= 1; i--) all.push_back(down[i]);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> S;
    vector < pt > all(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        all[i] = {x, y};
    }
    convex_hull(all);
    int opt_i = -1;
    int opt_j = -1;
    int opt_k = -1;
    ll mx_area = 0;
    //i, j, k
    int cur_sz = all.size();
    for (int i = 0; i < cur_sz; i++) all.push_back(all[i]);
    for (int i = 0; i < all.size() / 2; i++) {
        pt p = all[i];
        int cur_ptr = i + 2;
        if (cur_ptr >= all.size()) break;
        //i, j, k
        for (int j = i + 1; j < all.size() / 2; j++) {
            while (cur_ptr + 1 < all.size()) {
                ll cur_area = abs((all[cur_ptr] - p) * (all[j] - p));
                ll nxt_area = abs((all[cur_ptr + 1] - p) * (all[j] - p));
                if (cur_area < nxt_area) {
                    cur_ptr++;
                }
                else {
                    break;
                }
            }
            ll cur_area = abs((all[cur_ptr] - p) * (all[j] - p));
            if (cur_area > mx_area) {
                mx_area = cur_area;
                opt_i = i;
                opt_j = j;
                opt_k = cur_ptr;
            }
        }
    }
    vector < pt > ans(3);
    ans[0] = (all[opt_i] + all[opt_j]) - all[opt_k];
    ans[1] = (all[opt_i] + all[opt_k]) - all[opt_j];
    ans[2] = (all[opt_j] + all[opt_k]) - all[opt_i];
    for (auto& t : ans) {
        cout << t.x << " " << t.y << '\n';
    }
    return 0;
}
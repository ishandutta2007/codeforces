#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 100;
vector < pair < int, pair < int, int > > > que;
vector < int > nums;
int get_id(int x) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
}
int n;
vector < int > all[maxN];
vector < int > fenwAdd[maxN];
void fenwUpd(int l, int by, int what) {
    while (l < fenwAdd[what].size()) {
        fenwAdd[what][l] += by;
        l = (l | (l - 1)) + 1;
    }
}
int queryFenw(int r, int what) {
    int add = 0;
    while (r > 0) {
        add += fenwAdd[what][r];
        r = (r & (r - 1));
    }
    return add;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, t, x;
        cin >> a >> t >> x;
        nums.push_back(x);
        que.emplace_back(a, make_pair(t, x));
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (auto t : que) {
        int id = get_id(t.second.second);
        all[id].push_back(t.second.first);
    }
    for (int i = 1; i <= n; i++) {
        if (all[i].empty()) continue;
        sort(all[i].begin(), all[i].end());
        fenwAdd[i].resize(all[i].size() + 2);
    }
    for (auto t : que) {
        int what = get_id(t.second.second);
        int where = lower_bound(all[what].begin(), all[what].end(), t.second.first) - all[what].begin() + 1;
        //cout << what << " " << where << " here" << endl;
        if (t.first == 1) {
            fenwUpd(where, 1, what);
        }
        else if (t.first == 2) {
            fenwUpd(where, -1, what);
        }
        else {
            cout << queryFenw(where, what) << '\n';
        }
    }
}
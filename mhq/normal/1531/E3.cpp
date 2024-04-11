#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
const int maxN = 2e6 + 10;
int prefOne[maxN];
int prefZero[maxN];
int N;
/*int calc(int pos, int len) {
    if (len <= 1) return pos;
    int need_zeros = len / 2;
    int need_ones = (len + 1) / 2;
    if (prefZero[pos] < need_zeros && prefOne[pos] < need_ones) return -1;
    int l = -1;
    int r = pos;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (prefZero[pos] - prefZero[mid] > need_zeros || prefOne[pos] - prefOne[mid] > need_ones) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    /*int tr = -1;
    for (int cur = pos; ; cur--) {
        if (prefZero[pos] - prefZero[cur] == need_zeros || prefOne[pos] - prefOne[cur] == need_ones) {
            tr = cur;
            break;
        }
    }
    assert(tr == l);
    assert(prefZero[pos] - prefZero[l] == need_zeros || prefOne[pos] - prefOne[l] == need_ones);
    assert(prefZero[pos] - prefZero[l + 1] < need_zeros && prefOne[pos] - prefOne[l + 1] < need_ones);
    cout << pos << " " << len << " hihi " << l << " " << pos - l << endl;
//    for (int r = l + 1; r <= pos; r++) {
//        cout << s[r - 1];
//    }
//    cout << "----------------" << endl;
    int c1 = calc(r, need_ones);
    if (c1 == -1) return -1;
    return calc(c1, need_zeros);
}*/
bool can(int len) {
    vector<int> segs;
    function<void(int)> rec = [&](int x) {
        if (x <= 1) return;
        rec(x / 2);
        rec((x + 1) / 2);
        segs.emplace_back(x);
    };
    rec(len);
    int cur = 0;
    for (int i = 0; i < segs.size(); i++) {
        int need_zeros = segs[i] / 2;
        int need_ones = (segs[i] + 1) / 2;
        while (cur < N) {
            if (s[cur] == '0') need_zeros--;
            if (s[cur] == '1') need_ones--;
            cur++;
            if (!need_ones || !need_zeros) break;
        }
        if (need_ones > 0 && need_zeros > 0) return false;
    }
    return true;
}
int a[maxN];
void go(int le, int ri, int id_seg, vector<int>& poses, vector<int>& t) {
    if (le == ri) {
        a[le] = t[0];
        return;
    }
    int len = t.size();
    int need_ones = (len + 1) / 2;
    int need_zeros = len / 2;
    vector<int> to_left, to_right;
    int cur_sz = 0;
    for (int x = poses[id_seg - 1]; x < poses[id_seg]; x++) {
        if (s[x] == '0') {
            to_left.emplace_back(t[cur_sz++]);
        }
        else {
            to_right.emplace_back(t[cur_sz++]);
        }
    }
    assert((int)to_left.size() == need_zeros || (int)to_right.size() == need_ones);
    while ((int)to_left.size() < need_zeros) {
        to_left.emplace_back(t[cur_sz++]);
    }
    while ((int)to_right.size() < need_ones) {
        to_right.emplace_back(t[cur_sz++]);
    }
    go(ri - need_ones + 1, ri, id_seg - 1, poses, to_right);
    go(le, le + need_zeros - 1, id_seg - (need_ones), poses, to_left);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> s;
    N = s.size();
    for (int i = 1; i <= N; i++) {
        prefOne[i] = prefOne[i - 1] + (s[i - 1] == '1');
        prefZero[i] = prefZero[i - 1] + (s[i - 1] == '0');
    }
    int l = 1;
    int r = 1000001;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (can(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    assert(can(l));
    vector<int> segs;
    function<void(int)> rec = [&](int x) {
        if (x <= 1) return;
        rec(x / 2);
        rec((x + 1) / 2);
        segs.emplace_back(x);
    };
    rec(l);
    int cur = 0;
    vector<int> ptr;
    ptr.emplace_back(0);
    for (int i = 0; i < segs.size(); i++) {
        int need_zeros = segs[i] / 2;
        int need_ones = (segs[i] + 1) / 2;
        while (cur < N) {
            if (s[cur] == '0') need_zeros--;
            if (s[cur] == '1') need_ones--;
            cur++;
            if (!need_zeros || !need_ones) break;
        }
        ptr.emplace_back(cur);
    }
    assert(cur == N);

    vector<int> all(l);
    iota(all.begin(), all.end(), 1);
    go(0, l - 1, ptr.size() - 1, ptr, all);
    cout << l << '\n';
    for (int i = 0; i < l; i++) cout << a[i] << " ";
    return 0;
}
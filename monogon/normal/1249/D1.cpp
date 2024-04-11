
#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct seg {
    int l, r, idx;
    bool operator<(const seg &s) const {
        return r == s.r ? l < s.l : r > s.r;
    }
};

const int N = 2e5 + 5;
int n, k, l, r;
vector<int> L[N], R[N];
seg segs[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        segs[i] = {l, r, i};
    }
    sort(segs, segs + n);
    for(int i = 0; i < n; i++) {
        L[segs[i].l].push_back(i);
        R[segs[i].r].push_back(i);
    }
    set<int> s;
    set<int> rem;
    for(int i = 1; i < N; i++) {
        for(int x : L[i]) {
            s.insert(x);
        }
        while(s.size() > k) {
            rem.insert(segs[*s.begin()].idx + 1);
            s.erase(s.begin());
        }
        for(int x : R[i]) {
            s.erase(x);
        }
    }
    cout << rem.size() << endl;
    for(int x : rem) {
        cout << x << " ";
    }
    cout << endl;
}
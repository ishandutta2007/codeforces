#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
int mat[350][350];
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<pair<int, int>, int> > v;

int fix(int i) { return i >= 8 ? i - 8 : i; }

void upd(int t) {
    vector<pair<pair<int, int>, int> > v2;
    for (auto i : v) {
        int r = i.A.A, c = i.A.B, d = i.B;
        for (int j = 0; j < t; j++) {
            r += dr[d], c += dc[d];
            mat[r][c] = 1;
        }
        v2.push_back(MP(MP(r, c), fix(d + 1)));
        v2.push_back(MP(MP(r, c), fix(d + 7)));
    }

    v = v2;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

int main() {
    cin >> n;
    v.push_back(MP(MP(175, 175), 0));
    
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        upd(t);
    }

    int ans = 0;
    for (int i = 0; i < 350; i++)
        for (int j = 0; j < 350; j++)
            ans += mat[i][j];
    cout << ans << '\n';
}
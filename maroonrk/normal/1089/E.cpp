#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

#define rep(i,N) for(int i=0;i<(int)N;i++)
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

using P = pair<int, int>;
const int d4[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
};

bool vis[8][8];

void fil(P p) {
    vis[p.first][p.second] = true;
}
bool bc(P p) {
    return 0 <= p.first && p.first < 8 && 0 <= p.second && p.second < 8;
}

P move_s(P p, int dir) {
    if (!bc(p)) return P(-1, -1);
    if (!vis[p.first][p.second]) return p;
    P np = P(p.first + d4[dir][0], p.second + d4[dir][1]);
    return move_s(np, dir);
}

P move_b(P p, int dir) {
    if (!bc(p)) return P(-1, -1);
    P np = P(p.first + d4[dir][0], p.second + d4[dir][1]);
    P ans = move_b(np, dir);
    if (ans.first != -1) return ans;
    if (vis[p.first][p.second]) return P(-1, -1);
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; n++;
    vis[0][0] = true;
    P st = P(0, 0);
    V<P> pos;
    pos.push_back(st);
    while (int(pos.size()) < n - 2) {
        if (st.first == 7) {
            P u = move_b(st, 2);
            if (u.first != -1) {
                pos.push_back(u);
                st = u;
                fil(st);
                continue;
            }
            P v = move_s(st, 0);
            if (v.first != -1) {
                pos.push_back(v);
                st = v;
                fil(st);
                continue;
            }
        } else {
            P u = move_b(st, 0);
            if (u.first != -1) {
                pos.push_back(u);
                st = u;
                fil(st);
                continue;
            }
            P v = move_s(st, 2);
            if (v.first != -1) {
                pos.push_back(v);
                st = v;
                fil(st);
                continue;
            }
            P w = move_s(st, 1);
            if (w.first != -1) {
                pos.push_back(w);
                st = w;
                fil(st);
                continue;
            }
        }
        assert(false);
    }
    if (st == P(6, 7)) {
        pos.pop_back();
        pos.push_back(P(6, 6));
        pos.push_back(P(6, 7));
    } else if (st.first == 7) {
        pos.push_back(move_s(st, 0));
    } else if (st.second == 7) {
        pos.push_back(move_s(st, 1));
    } else {
        pos.push_back(move_b(st, 1));
    }
    pos.push_back(P(7, 7));

    for (auto p: pos) {
        cout << char('a' + p.second) << p.first+1 << " ";
    }
    cout << endl;
    return 0;
}
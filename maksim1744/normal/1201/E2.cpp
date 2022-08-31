/*
    author:  Maksim1744
    created: 10.04.2021 23:40:03
*/

#include "bits/stdc++.h"

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
// #define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

using FL = array<array<short, 1000>, 1000>;

array<pair<int, int>, 1000 * 1000 * 2> q;

const vector<pair<int, int>> D = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    auto get_dists = [&](int x, int y) {
        FL d;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                d[i][j] = (1 << 14);
            }
        }
        d[x][y] = 0;
        int ql = 0, qr = 0;
        q[qr] = {x, y};
        qr = 1;
        while (ql < qr) {
            if (ql % 1000 == 0)
                cerr << ql << ' ' << qr << endl;
            auto [x, y] = q[ql];
            ++ql;
            for (auto [dx, dy] : D) {
                int x1 = x + dx;
                int y1 = y + dy;
                if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
                if (d[x1][y1] <= d[x][y] + 1) continue;
                d[x1][y1] = d[x][y] + 1;
                q[qr] = {x1, y1};
                ++qr;
            }
        }
        return d;
    };
    auto dist_white = get_dists(n / 2 - 1, m / 2 - 1);
    auto dist_black = get_dists(n / 2, m / 2 - 1);
    pair<int, int> pw, pb;
    cin >> pw >> pb;
    pw.first--;
    pw.second--;
    pb.first--;
    pb.second--;

    pair<int, int> needb = {n / 2, m / 2 - 1};
    pair<int, int> needw = {n / 2 - 1, m / 2 - 1};

    auto col = [&](pair<int, int> p) {
        return (p.first + p.second) % 2;
    };

    auto covered = [&](pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second) == 3 && a.first != b.first && a.second != b.second;
    };

    auto manh = [&](pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    auto get_move = [&](pair<int, int> me, pair<int, int> he, const FL &target_dists) {
        if (covered(me, he)) {
            cout << he.first + 1 << ' ' << he.second + 1 << endl;
            exit(0);
        }
        pair<int, int> best = {-1, -1};
        for (auto [dx, dy] : D) {
            int x1 = me.first + dx;
            int y1 = me.second + dy;
            if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
            if (covered({x1, y1}, he)) continue;
            if (best.first == -1) {
                best = {x1, y1};
                continue;
            }
            if (target_dists[best.first][best.second] < target_dists[x1][y1]) continue;
            // if (manh(best, he) < manh({x1, y1}, he)) continue;
            best = {x1, y1};
        }
        assert(best.first != -1);
        return best;
    };

    auto start_black = [&]() {
        cout << "BLACK" << endl;
        cin >> pw;
        --pw.first;
        --pw.second;
    };

    auto start_white = [&] () {
        cout << "WHITE" << endl;
    };

    auto play_black = [&](const FL &targetd) {
        while (targetd[pb.first][pb.second] != 0) {
            pb = get_move(pb, pw, targetd);
            cout << pb.first + 1 << ' ' << pb.second + 1 << endl;
            if (pb == needb) {
                exit(0);
            }
            assert(pb != pw);
            cin >> pw;
            --pw.first;
            --pw.second;
            if (targetd[pb.first][pb.second] == 0) break;
        }
    };
    auto play_white = [&](const FL &targetd) {
        while (targetd[pw.first][pw.second] != 0) {
            pw = get_move(pw, pb, targetd);
            cout << pw.first + 1 << ' ' << pw.second + 1 << endl;
            if (pw == needw) {
                exit(0);
            }
            assert(pw != pb);
            cin >> pb;
            --pb.first;
            --pb.second;
            if (targetd[pw.first][pw.second] == 0) break;
        }
    };

    // auto mark_path = [&](const FL &d, pair<int, int> p) {
    //     vector<pair<int, int>> cur = {p};
    //     int curd = d[p.first][p.second];
    //     map<int, vector<pair<int, int>>> res;
    //     res[curd].pb(p);
    //     while (curd != 0) {
    //         vector<pair<int, int>> next;
    //         for (auto [x, y] : cur) {
    //             for (auto [dx, dy] : D) {
    //                 if (x + dx < 0 || y + dy < 0 || x + dx >= n || y + dy >= m) continue;
    //                 if (d[x + dx][y + dy] != curd - 1) continue;
    //                 show(x+dx, y+dy, d[x+dx][y+dy]);
    //                 next.eb(x + dx, y + dy);
    //             }
    //         }
    //         sort(next.begin(), next.end());
    //         next.erase(unique(next.begin(), next.end()), next.end());
    //         --curd;
    //         res[curd] = next;
    //         swap(cur, next);
    //     }
    //     return res;
    // };

    // show(col(pw), col(pb));
    // show(dist_black[pb.first][pb.second], dist_white[pw.first][pw.second]);

    if (col(pw) == col(pb)) {
        // white can't take, black safe
        if (dist_black[pb.first][pb.second] < dist_white[pw.first][pw.second]) {
            start_black();
            play_black(dist_black);
            return 0;
        } else if (dist_white[pb.first][pb.second] <= dist_white[pw.first][pw.second] + 1) {
            start_black();
            play_black(dist_white);
            play_black(dist_black);
            return 0;
        } else {
            show(dist_white);
            start_white();
            play_white(dist_white);
            return 0;
        }
    } else {
        // black can't take, white safe
        if (dist_black[pb.first][pb.second] >= dist_white[pw.first][pw.second]) {
            start_white();
            play_white(dist_white);
            return 0;
        } else if (dist_black[pb.first][pb.second] + 1 >= dist_black[pw.first][pw.second]) {
            start_white();
            play_white(dist_black);
            play_white(dist_white);
            return 0;
        } else {
            // if (dist_black[pb.first][pb.second] == dist_white[pw.first][pw.second] - 2) {
            //     show(pb);
            //     show(needb);
            //     auto vb = mark_path(dist_black, pb);
            //     auto vw = mark_path(dist_white, pw);
            //     pair<int, int> targ = {-1, -1};
            //     show(vw);
            //     show(vb);
            //     show(dist_black);
            //     for (auto [dd, cells] : vw) {
            //         for (auto c : cells) {
            //             bool ok = true;
            //             for (auto cb : vb[dd]) {
            //                 if (!covered(c, cb)) {
            //                     ok = false;
            //                     break;
            //                 }
            //             }
            //             if (ok) {
            //                 targ = c;
            //                 break;
            //             }
            //         }
            //     }
            //     show(targ);
            //     if (targ.first != -1) {
            //         start_white();
            //         auto dt = get_dists(targ.first, targ.second);
            //         show(dt);
            //         play_white(dt);
            //         play_white(dist_white);
            //         return 0;
            //     }
            // }
            start_black();
            play_black(dist_black);
            return 0;
        }
    }

    return 0;
}
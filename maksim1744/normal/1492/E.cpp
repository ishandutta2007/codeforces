/*
    author:  Maksim1744
    created: 23.02.2021 12:47:19
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
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    cin >> v;
    vector<int> same = v[0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (same[j] != v[i][j])
                same[j] = -1;
        }
    }
    vector<int> inds;
    {
        for (int i = 0; i < same.size(); ++i) {
            if (same[i] == -1)
                inds.pb(i);
        }
        vector<vector<int>> v2(n, vector<int>(inds.size()));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < inds.size(); ++j) {
                v2[i][j] = v[i][inds[j]];
            }
        }
        same = v[0];
        swap(v, v2);
        m = inds.size();

        // for (int i = 0; i < same.size(); ++i) {
        //     if (same[i] == -1)
        //         same[i] = 12345;
        // }
    }
    if (m <= 2) {
        cout << "Yes\n";
        cout << same << '\n';
        return 0;
    }

    vector<vector<int>> dif1(n);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[0][j] != v[i][j])
                dif1[i].pb(j);
        }
        if (dif1[i].size() > 4) {
            cout << "No\n";
            return 0;
        }
    }

    show(same, inds);
    show(dif1);
    show(v);

    // for (int i = 0; i < inds.size(); ++i) {
    //     same[inds[i]] = v[0][inds[i]];
    // }
    show(same);

    vector<pair<int, int>> unsure;
    for (int i1 = 0; i1 < m; ++i1) {
        for (int i2 = 0; i2 < i1; ++i2) {
            pair<int, int> sure = {-1, -1};
            unsure.clear();
            bool ok = true;
            for (int i = 1; i < n; ++i) {
                int other = 0;
                pair<int, int> cur;
                cur.first = v[i][i1];
                cur.second = v[i][i2];
                for (int k : dif1[i]) {
                    if (k != i1 && k != i2) {
                        ++other;
                    }
                }
                if (other > 2) {
                    ok = false;
                    break;
                }
                if (other == 0) continue;
                if (other == 2) {
                    if (sure.first == -1) {
                        sure = cur;
                    } else if (sure != cur) {
                        ok = false;
                        break;
                    }
                } else {
                    unsure.pb(cur);
                }
            }
            if (!ok) continue;
            show(unsure, sure);

            if (sure.first != -1) {
                for (auto p : unsure) {
                    if (p.first != sure.first && p.second != sure.second) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                same[inds[i1]] = sure.first;
                same[inds[i2]] = sure.second;
                cout << "Yes\n";
                cout << same << '\n';
                return 0;
            }
            if (unsure.empty()) {
                sure = {1, 1};
                same[inds[i1]] = sure.first;
                same[inds[i2]] = sure.second;
                cout << "Yes\n";
                cout << same << '\n';
                return 0;
            }
            {
                sure = {-1, -1};
                sure.first = unsure[0].first;
                for (auto [x, y] : unsure) {
                    if (x != sure.first) {
                        if (sure.second == -1)
                            sure.second = y;
                        else if (sure.second != y) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    if (sure.second == -1)
                        sure.second = 1;
                    same[inds[i1]] = sure.first;
                    same[inds[i2]] = sure.second;
                    cout << "Yes\n";
                    cout << same << '\n';
                    return 0;
                }
            }
            ok = true;
            {
                sure = {-1, -1};
                sure.second = unsure[0].second;
                for (auto [x, y] : unsure) {
                    if (y != sure.second) {
                        if (sure.first == -1)
                            sure.first = x;
                        else if (sure.first != x) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) {
                    if (sure.first == -1)
                        sure.first = 1;
                    same[inds[i1]] = sure.first;
                    same[inds[i2]] = sure.second;
                    cout << "Yes\n";
                    cout << same << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "No\n";

    return 0;
}
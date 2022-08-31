/*
    author:  Maksim1744
    created: 30.05.2021 23:39:48
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> towers(n);
    cin >> towers;
    vector<pair<int, pair<int, int>>> quests(m);
    for (int i = 0; i < m; ++i) {
        cin >> quests[i].second >> quests[i].first;
    }
    sort(quests.begin(), quests.end());

    auto dist = [&](const pair<int, int> &a, const pair<int, int> &b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    const int inf = 1e9 + 1e5;

    vector<vector<int>> tower_dist(1 << n, vector<int>(n, inf));
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                tower_dist[mask][i] = 0;
                continue;
            }
            for (int j = 0; j < n; ++j)
                if ((mask >> j) & 1)
                    umin(tower_dist[mask][i], dist(towers[i], towers[j]));
        }
    }
    vector<vector<int>> quest_dist(1 << n, vector<int>(m, inf));
    for (int mask = 0; mask < (1 << n); ++mask)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if ((mask >> j) & 1)
                    umin(quest_dist[mask][i], dist(quests[i].second, towers[j]));

    vector<vector<int>> dp_tower(1 << n, vector<int>(m + 1, inf));
    vector<vector<int>> dp_quest(1 << n, vector<int>(m, -inf));

    for (int i = 0; i < m; ++i)
        dp_quest[0][i] = 1;
    for (int i = 0; i < n; ++i)
        dp_tower[1 << i][0] = 0;

    for (int its = 0; its <= m; ++its) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int q = 0; q < m; ++q) {
                if (dp_quest[mask][q] != its) continue;
                if (dp_quest[mask][q] < 0) continue;

                // walk to new quest
                for (int q2 = q + 1; q2 < m; ++q2)
                    if (quests[q].first + dist(quests[q].second, quests[q2].second) <= quests[q2].first)
                        umax(dp_quest[mask][q2], dp_quest[mask][q] + 1);

                // jump to tower group after quest
                umin(dp_tower[mask][dp_quest[mask][q]], quests[q].first);

                // new tower after quest
                for (int i = 0; i < n; ++i)
                    umin(dp_tower[mask | (1 << i)][dp_quest[mask][q]], quests[q].first + dist(quests[q].second, towers[i]));
            }
        }
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cnt = its;
            {
                // walk from tower group to new tower
                for (int i = 0; i < n; ++i)
                    umin(dp_tower[mask | (1 << i)][cnt], dp_tower[mask][cnt] + tower_dist[mask][i]);

                // walk to new quest from tower group
                for (int q = 0; q < m; ++q)
                    if (dp_tower[mask][cnt] + quest_dist[mask][q] <= quests[q].first)
                        umax(dp_quest[mask][q], cnt + 1);
            }
        }
    }

    int ans = 0;
    for (auto &a : dp_quest)
        for (auto &b : a)
            umax(ans, b);
    cout << ans << '\n';

    return 0;
}
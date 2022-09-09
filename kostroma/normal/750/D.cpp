#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }

    /*while (true) {
        solve(false);
    }*/

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

void precalc() {

}

//#define int li

//const int mod = 1000000007;

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1 };

struct State {
    int x, y;
    int dir;
    bool operator < (const State& ot) const {
        if (x != ot.x) {
            return x < ot.x;
        }
        if (y != ot.y) {
            return y < ot.y;
        }
        return dir < ot.dir;
    }
    bool operator == (const State& ot) const {
        return x == ot.x && y == ot.y && dir == ot.dir;
    }
};

void solve(bool read) {
    int n;
    cin >> n;
    vector<int> t(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        sum += t[i];
    }
    State start = {0, 0, 0};
    vector<vector<State>> states(sum + 1);
    states[0].push_back(start);
    int pref = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t[i]; ++j) {
            sort(all(states[pref]));
            states[pref].erase(unique(all(states[pref])), states[pref].end());
            for (auto& item : states[pref]) {
                if (j + 1 == t[i]) {
                    for (int dom = -1; dom <= 1; dom += 2) {
                        int next_dir = (item.dir + dom + 8) % 8;
                        states[pref + 1].push_back({item.x + dx[next_dir], item.y + dy[next_dir], next_dir});
                    }
                }
                else {
                    states[pref + 1].push_back({item.x + dx[item.dir], item.y + dy[item.dir], item.dir});
                }
            }
            ++pref;
        }
    }

    set<pair<int, int>> visited;
    for (int i = 0; i < sum; ++i) {
        for (auto& item : states[i]) {
            visited.insert({item.x, item.y});
        }
    }
    cout << visited.size() << endl;

}
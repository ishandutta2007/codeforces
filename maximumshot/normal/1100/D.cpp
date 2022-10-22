#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int K = 666;
const int X = 999;

pii s;
pii a[K];
int used[X + 1][X + 1];

void ask(int x, int y) {
    cout << x << " " << y << endl;
    int k;
    cin >> k >> x >> y;
    if(k == -1) exit(0);
    k--;
    used[ a[k].first ][ a[k].second ]--;
    a[k] = {x, y};
    used[ a[k].first ][ a[k].second ]++;
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s.first >> s.second;

    for(int i = 0;i < K;i++) {
        cin >> a[i].first >> a[i].second;
        used[ a[i].first ][ a[i].second ]++;
    }

    while(s.first < 500) {
        s.first++;
        ask(s.first, s.second);
    }

    while(s.first > 500) {
        s.first--;
        ask(s.first, s.second);
    }

    while(s.second < 500) {
        s.second++;
        ask(s.first, s.second);
    }

    while(s.second > 500) {
        s.second--;
        ask(s.first, s.second);
    }

    vector< pii > t = {
        {-1, -1}, {-1, +1}, {+1, +1}, {+1, -1}
    };

    int p = -1, sc = inf;

    for(int pp = 0;pp < 4;pp++) {
        int di, dj;
        tie(di, dj) = t[pp];
        int tmp = 0;
        for(int i = 500 + di;1 <= i && i <= X;i += di) {
            for(int j = 500 + dj;1 <= j && j <= X;j += dj) {
                tmp += used[i][j];
            }
        }
        if(tmp < sc) {
            sc = tmp;
            p  = pp;
        }
    }

//    p = (p + 2) % 4;

    int di, dj;

    tie(di, dj) = t[p];

    di = -di;
    dj = -dj;

    s = {500, 500};

    while(1) {
        if(used[s.first + di][s.second + dj]) {
            s.first += di;
            ask(s.first, s.second);
        }
        s.first += di;
        s.second += dj;
        ask(s.first, s.second);
    }

    return 0;
}
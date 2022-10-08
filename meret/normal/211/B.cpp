#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define VAR(i, x) __typeof(x) i = (x)
#define FORE(i, x) for (VAR(i, (x).begin()); i != (x).end(); ++i)
#define FOR(i,a,b) for (i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (i = (a); i >= (b); --i)
#define REP(i,x) for(i = 0; i < (x); ++i)
#define MP make_pair
#define PB push_back

typedef pair<int, int> PII;
typedef long long LL;

string s;
int n;

map<int, int> results;

vector<int> positions[27];

int cnt[1000005][27];

void check(int a, int b) {
    if (a > b) {
        return;
    }
    int x = 0;
    if (b - a < 26) {
        for (int i = a; i <= b; ++i) {
            x |= 1 << (s[i] - 'a');
        }
    } else {
        for (int i = 0; i < 26; ++i) {
            if (cnt[b][i] > cnt[a - 1][i]) {
                x |= 1 << i;
            }
        }
    }
    map<int, int>::iterator it = results.find(x);
    if (it != results.end()) {
        ++it->ND;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.size();
    int m;
    cin >> m;
    vector<string> z(m);
    vector<int> x(m);
    for (int i = 0; i < m; ++i) {
        cin >> z[i];
        x[i] = 0;
        for (int j = 0; j < (int) z[i].size(); ++j) {
            x[i] |= (1 << (z[i][j] - 'a'));
        }
        results[x[i]] = 0;
    }
    s = "#" + s + "#";
    for (int i = 1; i <= n; ++i) {
        positions[s[i] - 'a'].PB(i);
        for (int j = 0; j < 26; ++j) {
            cnt[i][j] = cnt[i - 1][j];
        }
        ++cnt[i][s[i] - 'a'];
    }
    positions[26].PB(0);
    positions[26].PB(n + 1);
    for (int i = 0; i <= 26; ++i) {
        for (int j = i + 1; j <= 26; ++j) {
            int li = 0;
            int lj = 0;
            while (li < (int) positions[i].size() && lj < (int) positions[j].size()) {
                if (positions[i][li] < positions[j][lj]) {
                    if (li + 1 == (int) positions[i].size() || positions[i][li + 1] > positions[j][lj]) {
                        check(positions[i][li] + 1, positions[j][lj] - 1);
                    }
                    ++li;
                } else {
                    if (lj + 1 == (int) positions[j].size() || positions[j][lj + 1] > positions[i][li]) {
                        check(positions[j][lj] + 1, positions[i][li] - 1);
                    }
                    ++lj;
                }
            }
        }
        for (int li = 0; li + 1 < (int) positions[i].size(); ++li) {
            check(positions[i][li] + 1, positions[i][li + 1] - 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << results[x[i]] << "\n";
    }
}
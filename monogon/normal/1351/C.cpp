
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

int t;
string s;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int opp[4] = {1, 0, 3, 2};
map<char, int> ma = {{'N', 0}, {'S', 1}, {'W', 2}, {'E', 3}};

struct node {
    int x, y, dir;
    node(int x, int y, int dir): x(x), y(y), dir(dir) {}
    bool operator<(const node &o) const {
        return tuple(x, y, dir) < tuple(o.x, o.y, o.dir);
    }
};
set<node> se;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        se.clear();
        int x = 0, y = 0;
        int ti = 0;
        for(char c : s) {
            int d = ma[c];
            if(se.count({x, y, d}) == 0) {
                ti += 5;
                se.emplace(x, y, d);
                se.emplace(x + dx[d], y + dy[d], opp[d]);
            }else ti++;
            x += dx[d];
            y += dy[d];
        }
        cout << ti << '\n';
    }
}
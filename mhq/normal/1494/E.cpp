#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
map<pair<int,int>, char> mp;
map<int, int> for_two[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int A = 0;
    int B = 0;
    auto add = [&](int x, int y, char c) {
        mp[make_pair(x, y)] = c;
        if (mp.count(make_pair(y, x))) {
            char d = mp[make_pair(y, x)];
            if (d == c) A++;
            else {
                B++;
            }
            /*else {
                int he = 26 * (c - 'a') + (d - 'a');
                int nhe = 26 * (d - 'a') + (c - 'a');
                if (for_two[y].count(he)) {
                    B += for_two[y][he];
                }
                if (for_two[x].count(nhe)) {
                    B += for_two[x][nhe];
                }
                for_two[y][he]++;
                for_two[x][nhe]++;
            }*/
        }
    };
    auto del = [&](int x, int y) {
        char c = mp[make_pair(x, y)];
        mp.erase(make_pair(x, y));
        if (mp.count(make_pair(y, x))) {
            char d = mp[make_pair(y, x)];
            if (d == c) A--;
            else B--;
            /*else {
                int he = 26 * (c - 'a') + (d - 'a');
                int nhe = 26 * (d - 'a') + (c - 'a');
                if (for_two[y].count(he)) {
                    B -= for_two[y][he];
                }
                if (for_two[x].count(nhe)) {
                    B -= for_two[x][nhe];
                }
                for_two[x][he]--;
                for_two[y][nhe]--;
            }*/
        }
    };
    while (m--) {
        char tp;
        cin >> tp;
        if (tp == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            add(u, v, c);
        }
        else if (tp == '-') {
            int u, v;
            cin >> u >> v;
            del(u, v);
        }
        else {
            int k;
            cin >> k;
            if (k % 2 == 0) {
                if (A > 0) cout << "YES\n";
                else cout << "NO\n";
            }
            else {
                if (A > 0 || B > 0) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}
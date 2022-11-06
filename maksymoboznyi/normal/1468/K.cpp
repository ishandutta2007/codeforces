#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 101;

string s;
int t;
vector<pair<int, int> > can;

bool check(int ax, int ay) {
    int x = 0, y = 0;
    for (auto c : s) {
        if (c == 'L' && (x - 1 != ax || y != ay))
            x--;
        if (c == 'R' && (x + 1 != ax || y != ay))
            x++;
        if (c == 'U' && (x != ax || y + 1 != ay))
            y++;
        if (c == 'D' && (x != ax || y - 1 != ay))
            y--;
    }
    return (x == 0 && y == 0);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        can.clear();
        int x = 0, y = 0;
        for (auto c : s) {
            if (c == 'L')
                x--;
            if (c == 'R')
                x++;
            if (c == 'U')
                y++;
            if (c == 'D')
                y--;
            can.pb({x, y});
        }
        bool is = 0;
        for (auto [x, y] : can)
            if (check(x, y)) {
                is = 1;
                cout << x << ' ' << y << "\n";
                break;
            }
        if (!is)
            cout << "0 0\n";

    }

    return 0;
}
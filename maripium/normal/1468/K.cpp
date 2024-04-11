#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        []() {
        string S; cin >> S;
        vector<pair<int, int>> cnd;
        int x = 0, y = 0;
        for (char c : S) {
            switch(c) {
                case 'L' : x--; break;
                case 'R' : x++; break;
                case 'U' : y++; break;
                case 'D' : y--; break;
            }
            if (x || y) cnd.emplace_back(x, y);
        }
        for (auto [ox, oy] : cnd) {
            int x = 0, y = 0;
            for (char c : S) {
                int nx = x, ny = y;
                switch(c) {
                    case 'L' : nx--; break;
                    case 'R' : nx++; break;
                    case 'U' : ny++; break;
                    case 'D' : ny--; break;
                }
                if (nx == ox && ny == oy) continue;
                x = nx; y = ny;
            }
            if (x == 0 && y == 0) {
                cout << ox << ' ' << oy << '\n';
                return;
            }
        }
        cout << "0 0\n";
        }();
    }
}
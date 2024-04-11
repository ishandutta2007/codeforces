#include <bits/stdc++.h>
using namespace std;

const int DX[4] = {0, -1, 0, 1}, DY[4] = {1, 0, -1, 0};
const map<char, int> D = {{'U', 0}, {'L', 1}, {'D', 2}, {'R', 3}};

int t;
string s;

bool test(int bx, int by, string s) {
    int x = 0, y = 0;
    for (char c : s) {
        x += DX[D.at(c)]; y += DY[D.at(c)];
        if (x == bx && y == by) {
            x -= DX[D.at(c)]; y -= DY[D.at(c)];
        }
    }
    return x == 0 && y == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> s;
        vector<pair<int, int>> bl;
        int x = 0, y = 0;
        for (char c : s) {
            x += DX[D.at(c)]; y += DY[D.at(c)];
            bl.push_back({x, y});
        }
        int ax = 0, ay = 0;
        for (auto [x, y] : bl) {
            if (test(x, y, s)) {
                ax = x; ay = y;
                break;
            }
        }
        cout << ax << " " << ay << '\n';
    }
}
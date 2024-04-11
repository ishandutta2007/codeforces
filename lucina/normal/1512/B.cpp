#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 5;


int main() {


    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    for (int _ = 1 ; _ <= T ; ++ _) {
        static char s[512];
        int n;
        cin >> n;
        pair <int, int> bar[2];
        int t = 0;
        for (int i = 0 ; i < n ; ++ i) {
            cin >> s;
            for (int j = 0 ; j < n ; ++ j) {
                if (s[j] == '*') {
                    bar[t ++] = make_pair(i, j);
                }
            }
        }

        set <pair <int, int>> marked;
        for (int x : {bar[0].first, bar[1].first})
        for (int y : {bar[0].second, bar[1].second})
            marked.emplace(x, y);

        if (marked.size() == 2) {
            auto [x1, y1] = *marked.begin();
            auto [x2, y2] = *prev(marked.end());

            if (x1 == x2) {
                if (x1) -- x1;
                else ++ x1;
                marked.emplace(x1, y1);
                marked.emplace(x1, y2);
            } else if (y1 == y2) {
                if (y1) -- y1;
                else ++ y1;
                marked.emplace(x1, y1);
                marked.emplace(x2, y1);
            }
        }

        for (int i = 0 ; i < n ; ++ i, cout << '\n')
            for (int j = 0 ; j < n ; ++ j)
                cout << (marked.count(make_pair(i, j)) ? "*" : ".");
    }

}
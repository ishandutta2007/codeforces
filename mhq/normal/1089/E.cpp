#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string r = "abcdefgh";
    string c = "12345678";
    basic_string< pair<int, int> > snake;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int k = j;
            if (i & 1) {
                k = 7 - k;
            }
            snake += make_pair(k, i);
        }
    }

    auto snk2 = snake.substr(16);

    auto getSnake = [&](int n) {
        auto snk = snake;
        int on = n;
        int ptr = 0;
        const int poses[] = {17, 21, 25, 29};
        if (n == 63) {
            snk.erase(56);
            basic_string<pair<int, int> > ins = {{0, 7}, {6, 7}, {5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}};
            snk.insert(49, ins);
            snk += make_pair(7, 7);
            return snk;
        }
        if (n > 56) {
            snk.erase(56);
            while (n > 56) {
                basic_string<pair<int, int> > ins = {{ptr * 2,     7},
                                                     {ptr * 2 + 1, 7}};
                snk.insert(poses[ptr], ins);
                ++ptr;
                n -= 2;
            }
            if (on == 63) {
                return snk;
            }
            if (n == 55) {
                snk.erase(1, 1);
            }
            snk += make_pair(7, 7);
            return snk;
        }
        if (n % 8 == 1) {
            snk.erase(1, 2);
        } else if (n % 8 == 2) {
            snk.erase(1, 1);
        }
        snk.erase(n-1);
        assert(snk.back().second != 7 && snk.back().first != 7);
        snk += make_pair(snk.back().first, 7);
        snk += make_pair(7, 7);
        return snk;
    };

    auto snk = getSnake(n);
    //cout << snk.size() << endl;
    assert(snk.size() == n+1);

    for (auto it : snk) {
        cout << r[it.first] << c[it.second] << " ";
    }
    cout << endl;

    return 0;
}
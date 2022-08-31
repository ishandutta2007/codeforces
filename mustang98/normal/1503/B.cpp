#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

vector<pair<int, int>> v1, v2;

void go(int i, int j, int col) {
    cout << col << ' ' << i + 1 << ' ' << j + 1 << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2 == 0) {
                v1.emplace_back(i, j);
            } else {
                v2.emplace_back(i, j);
            }
        }
    }
    for (int i = 0; i < n * n; ++i) {
        int c;
        cin >> c;
        bool can1 = (c != 1);
        bool can2 = (c != 2);
        if (can1 && !v1.empty()) {
            go(v1.back().F, v1.back().S, 1);
            v1.pop_back();
            continue;
        }
        if (can2 && !v2.empty()) {
            go(v2.back().F, v2.back().S, 2);
            v2.pop_back();
            continue;
        }
        if (can1 && v1.empty()) {
            go(v2.back().F, v2.back().S, 3);
            v2.pop_back();
            continue;
        }
        if (can2 && v2.empty()) {
            go(v1.back().F, v1.back().S, 3);
            v1.pop_back();
            continue;
        }
    }

    return 0;
}
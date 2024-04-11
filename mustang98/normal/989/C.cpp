#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 55, inf = 1000111222;

char f[max_n][max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    pair<int, char> p[4];
        p[0] = {a, 'A'};
    p[1] = {b, 'B'};
    p[2] = {c, 'C'};
    p[3] = {d, 'D'};
    sort(p, p + 4);
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 25; ++j) {
            f[i][j] = p[0].S;
        }
    }
    p[0].F--;
    for (int i = 0; i < 50; ++i) {
        for (int j = 25; j < 50; ++j) {
            f[i][j] = p[1].S;
        }
    }
    p[1].F--;
    for (int i = 0; i < 50; i += 2) {
        for (int j = 0; j < 12; j += 2) {
            if (p[1].F) {
                p[1].F--;
                f[i][j] = p[1].S;
            }
        }
    }
    for (int i = 0; i < 50; i += 2) {
        for (int j = 12; j < 25; j += 2) {
            if (p[2].F) {
                p[2].F--;
                f[i][j] = p[2].S;
            }
        }
    }
    for (int i = 0; i < 50; i += 2) {
        for (int j = 26; j < 38; j += 2) {
            if (p[0].F) {
                p[0].F--;
                f[i][j] = p[0].S;
            }
        }
    }
    for (int i = 0; i < 50; i += 2) {
        for (int j = 38; j < 50; j += 2) {
            if (p[3].F) {
                p[3].F--;
                f[i][j] = p[3].S;
            }
        }
    }
    cout << 50 << ' ' << 50 << endl;
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            cout << f[i][j];
        }
        cout << endl;
    }

    return 0;
}
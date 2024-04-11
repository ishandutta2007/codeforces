#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

vector<pair<int, int>> v;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n = 1000, m = 1000;
    cin >> n >> m;
    pair<int, int> cur = MP(1, 1);
    int w = m;
    for (int step = 1; step <= m / 2; ++step) {
        //v.PB(cur);
        for (int i = 1; i <= n; ++i) {
            v.emplace_back(i, step);
            v.emplace_back(n - i + 1, m - step + 1);
        }
    }
    if (m % 2 == 1) {
        int cury = m / 2 + 1;
        int curx = 1;
        int add = n - 1;
        int mn = 1;
        for (int i = 0; i < n; ++i) {
            v.emplace_back(curx, cury);
            curx += (add * mn);
            --add;
            mn *= -1;
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        printf("%d %d\n", v[i].F, v[i].S);
    }
    return 0;
}
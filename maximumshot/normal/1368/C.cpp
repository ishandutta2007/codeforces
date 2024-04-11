#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

set<pii> seq;
int x = 0, y = 0;

void mv(int dx, int dy) {
    x += dx;
    y += dy;
    seq.insert({x, y});
}

void mv(char c) {
    if (c == 'L')
        mv(-1, 0), mv(-1, 0);
    else if (c == 'R')
        mv(+1, 0), mv(+1, 0);
    else if (c == 'U')
        mv(0, +1), mv(0, +1);
    else // D
        mv(0, -1), mv(0, -1);
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    seq.insert({x, y});

    for (int i = 0; i < n; i++) {
        mv('R');
        mv('U');
        mv('L');
        mv('U');
        mv('R');
        mv('D');
        mv('R');
        mv('D');
        mv('R');
    }

    mv('D');
    while (x > 0)
        mv('L');
    mv('U');

    cout << (int) seq.size() << "\n";
    for (auto p : seq)
        cout << p.first << " " << p.second << "\n";

    return 0;
}
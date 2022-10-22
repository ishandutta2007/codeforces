#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    vec< pii > a(n), b(m);

    for(pii &p : a) {
        cin >> p.first >> p.second;
        if(p.first > p.second) swap(p.first, p.second);
    }
    for(pii &p : b) {
        cin >> p.first >> p.second;
        if(p.first > p.second) swap(p.first, p.second);
    }

    vec< int > can(10);

    for(int x = 1;x <= 9;x++) {
        for(int y = 1;y <= 9;y++) {
            if(x == y) continue;
            for(int z = 1;z <= 9;z++) {
                if(x == z || y == z) continue;

                int a1 = x, a2 = y;
                int b1 = y, b2 = z;

                if(a1 > a2) swap(a1, a2);
                if(b1 > b2) swap(b1, b2);

                auto ita = find(ALL(a), make_pair(a1, a2));
                auto itb = find(ALL(b), make_pair(b1, b2));

                if(ita == a.end() || itb == b.end()) continue;

                can[y] = 1;

            }
        }
    }

    if(count(ALL(can), 1) == 1) {
        cout << max_element(ALL(can)) - can.begin() << "\n";
        return 0;
    }

    for(int it = 0;it < 2;it++, swap(a, b)) {
        for(int x = 1;x <= 9;x++) {
            for(int y = 1;y <= 9;y++) {
                if(x == y) continue;
                int a1 = x;
                int a2 = y;
                if(a1 > a2) swap(a1, a2);
                if(find(ALL(a), make_pair(a1, a2)) == a.end()) continue;

                int isx = 0;
                int isy = 0;

                for(int z = 1;z <= 9;z++) {
                    if(x == z || y == z) continue;
                    vec< pii > candidate = {{x, z}, {y, z}};
                    for(pii &p : candidate) {
                        if(p.first > p.second) swap(p.first, p.second);
                        if(find(ALL(b), p) != b.end()) {
                            if(p.first == x || p.second == x) isx = 1;
                            if(p.first == y || p.second == y) isy = 1;
                        }
                    }
                }

                if(isx + isy > 1) {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    cout << "0\n";

    return 0;
}
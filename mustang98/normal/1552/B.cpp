#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 50111, inf = 1000111222;



int n;
int m[max_n][5];

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int solve() {
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        p.PB(i);
    }
    shuffle(p.begin(), p.end(), rnd);
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        int cur = p[i];
        for (int j = 0; j < n; ++j) {
            int to = p[j];
            if (to == cur) {
                continue;
            }
            int cnt = 0;
            for (int k = 0; k < 5; ++k) {
                cnt += (m[cur][k] < m[to][k]);
            }
            if (cnt < 3) {
                ok = false;
                break;
            }
        }
        //cout << "% " << ok << endl;
        if (ok) {
            return cur + 1;
        }
    }
    return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                scanf("%d", &m[i][j]);
            }
        }
        printf("%d\n", solve());

    }


    return 0;
}
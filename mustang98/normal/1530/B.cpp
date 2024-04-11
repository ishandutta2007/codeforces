#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 25, inf = 1000111222;

int calc(int x) {
    if (x <= 0) return 0;
    return (x + 1) / 2;
}

char ans[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int h, w;
        cin >> h >> w;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                ans[i][j] = '0';
            }
        }
        ans[0][0] = ans[h - 1][0] = ans[0][w - 1] = ans[h - 1][w - 1] = '1';
        int cnth = calc(h - 4);
        for (int i = 2;cnth;i += 2) {
            ans[i][0] = ans[i][w - 1] = '1';
            --cnth;
        }
        int cntw = calc(w - 4);
        for (int j = 2;cntw; j += 2){
            ans[0][j] = ans[h - 1][j] = '1';
            --cntw;
        }

        for (int i = 0; i < h; ++i) {
            for (int j =0 ; j < w; ++j) {
                cout << ans[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
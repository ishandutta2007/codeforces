#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int a[2][2];

    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 2;j++)
            cin >> a[i][j];

    if(a[0][0] == 0 && a[0][1] == 0 && a[1][0] == 0 && a[1][1] == 0) {
        cout << "0\n";
        return true;
    }

    vec< int > mas_c0;
    vec< int > mas_c1;

    // c0 * (c0 - 1) / 2 == a[0][0]

    for(int i = 0;1ll * i * (i - 1) / 2 <= 1ll * a[0][0];i++) {
        if(1ll * i * (i - 1) / 2 == 1ll * a[0][0]) {
            mas_c0.push_back(i);
        }
    }

    for(int i = 0;1ll * i * (i - 1) / 2 <= 1ll * a[1][1];i++) {
        if(1ll * i * (i - 1) / 2 == 1ll * a[1][1]) {
            mas_c1.push_back(i);
        }
    }

    for(int c0 : mas_c0) {
        for(int c1 : mas_c1) {

            if(c0 == 0 && c1 == 0) continue;

            if(c0 == 0) {
                if(a[0][1] == 0 && a[1][0] == 0) {
                    for(int i = 0;i < c1;i++) printf("1");
                    printf("\n");
                    return true;
                }
            }

            if(c1 == 0) {
                if(a[0][1] == 0 && a[1][0] == 0) {
                    for(int i = 0;i < c0;i++) printf("0");
                    printf("\n");
                    return true;
                }
            }

            //cout << "c0 = " << c0 << ", c1 = " << c1 << "\n";
            if(a[0][1] == 0) {
                // 11111 ... 111100000 ... 0000
                if(1ll * c1 * c0 != 1ll * a[1][0]) {
                }else {
                    for(int i = 0;i < c1;i++) printf("1");
                    for(int i = 0;i < c0;i++) printf("0");
                    printf("\n");
                    return true;
                }
            }

            if(a[1][0] == 0) {
                if(1ll * c0 * c1 != 1ll * a[0][1]) {
                }else {
                    for(int i = 0;i < c0;i++) printf("0");
                    for(int i = 0;i < c1;i++) printf("1");
                    printf("\n");
                    return true;
                }
            }

            if(1ll * c1 * c0 == a[0][1] + a[1][0]) {
                int cnt = a[0][1] / c0;
                int ost = a[0][1] % c0;
                if (ost > 0) {
                    for (int i = 0; i < c1 - cnt - 1; i++) printf("1");
                    for (int i = 0; i < ost; i++) printf("0");
                    printf("1");
                    for (int i = 0; i < c0 - ost; i++) printf("0");
                    for (int i = 0; i < cnt; i++) printf("1");
                    printf("\n");
                } else {
                    for (int i = 0; i < c1 - cnt; i++) printf("1");
                    for (int i = 0; i < c0; i++) printf("0");
                    for (int i = 0; i < cnt; i++) printf("1");
                    printf("\n");
                }
                return true;
            }
        }
    }

    cout << "Impossible\n";

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
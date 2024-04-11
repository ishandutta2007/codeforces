#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

int m[max_n][max_n];
int n;

void create() {
    int cur = 0;
    for (int i = 0; i < n; i += 4) {
        for (int j = 0; j < n; j += 4) {
            for (int c = 0; c < 4; ++c) {
                for (int d = 0; d < 4; ++d) {
                    m[i + c][j + d] = cur++;
                }
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    create();
    for (int i =0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    /*for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            s ^= m[i][j];
        }
        cout << s << endl;
    }
    cout << "=======" << endl;
    for (int j = 0; j < n; ++j) {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s ^= m[i][j];
        }
        cout << s << endl;
    }*/

    return 0;
}
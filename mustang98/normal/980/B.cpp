#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100, inf = 1000111222;

char m[4][max_n];
    int n, k;


void print() {
    cout << "YES" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < max_n; ++j) {
            m[i][j] = '.';
        }
    }
    cin >> n >> k;
    if (k % 2 == 0) {
        for (int i = 0; i < k / 2; ++i) {
            m[1][i + 1] = '#';
            m[2][i + 1] = '#';
        }
        print();
        return 0;
    }
    int cur = n / 2;
    m[1][cur] = '#';
    --k;
    for (int i = 0; i < (n - 3) / 2; ++i) {
        if (k == 0) break;
        m[1][n / 2 - i - 1] = '#';
        m[1][n / 2 + i + 1] = '#';
        k -= 2;
    }
    for (int i = 0; i < (n - 3) / 2; ++i) {
        if (k == 0) break;
        m[2][i + 1] = '#';
        m[2][n - i - 2] = '#';
        k -= 2;
    }
    print();
    return 0;
}
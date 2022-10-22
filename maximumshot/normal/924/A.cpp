#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 55;

int n, m;
int a[N][N];
int r[N][N];
bitset< N > bs[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            char c;
            cin >> c;
            a[i][j] = (c == '#');
            bs[j][i] = a[i][j];
        }
    }

    for(int i = 0;i < n;i++) {
        vec< int > cols;
        for(int j = 0;j < m;j++) {
            if(a[i][j]) {
                cols.push_back(j);
            }
        }
        for(int j : cols) {
            if(bs[j] != bs[cols.front()]) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";

    return 0;
}
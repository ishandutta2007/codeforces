#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    vec< vec< int > > t = {
        {0, 1},
        {2, 3}
    };

    int n = 50;
    int m = 50;
    int c[4];
    for(int i = 0;i < 4;i++) cin >> c[i];
    vec< vec< int > > mat(n, vec< int >(m, -1));

    string symb = "ABCD";

    for(int i = 0;i < 4;i++) {
        for(int j = 0;j < 3;j++) {
            if(c[j] > c[j + 1]) {
                swap(c[j], c[j + 1]);
                swap(symb[j], symb[j + 1]);
            }
        }
    }

    int cnt = c[0] - 1;
    int I = 0;

    for(int i = 0;i < n && cnt > 0;i += 2) {
        for(int j = 0;j < m && cnt > 0;j += 2) {
            mat[i][j] = 0;
            mat[i + 1][j] = mat[i][j + 1] = mat[i + 1][j + 1] = 1;
            cnt--;
        }
        I = i;
    }

    I += 3;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(mat[i][j] == -1) mat[i][j] = 0;
        }
    }

    c[1] -= (c[0] > 1);

    for(int i = I;i < n;i += 2) {
        for(int j = 0;j < m;j += 2) {
            int x = 1;
            while(x < 4 && !c[x]) x++;
            if(x < 4) mat[i][j] = x, c[x]--;
        }
    }

    cout << n << " " << m << "\n";

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << symb[mat[i][j]];
        }
        cout << "\n";
    }

    return 0;
}
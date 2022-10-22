#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool check(vec< vec< int > > const & a) {
    int n = (int)a.size();
    vec< int > str(n), col(n);
    int s1 = 0, s2 = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            str[i] ^= a[i][j];
            col[j] ^= a[i][j];
            if(i == j) s1 ^= a[i][j];
            if(i + j == n - 1) s2 ^= a[i][j];
        }
    }
    int ok = s1 & s2;
    for(int i = 0;i < n;i++) {
        ok &= str[i];
        ok &= col[i];
    }
    return ok;
}

bool solve() {

    int n;
    cin >> n;

    vec< vec< int > > a(n, vec< int >(n));

    if(n % 4 == 1) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(i + j < n - 1) a[i][j] = 1;
                else if(i + j == n - 1) a[i][j] = 1 - j % 2;
                else a[i][j] = 0;
            }
        }
    }else {
        for(int i = 0;i < n;i++) a[n / 2][i] = a[i][n / 2] = 1;
        for(int i = 0;i < n / 4;i++) {
            for(int j = 0;j < n;j++)
                a[i][j] = a[n - 1 - i][j] = 1;
        }
    }

    int val[2] = {2, 1};

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << val[a[i][j]] << ' ';
            val[a[i][j]] += 2;
        }
        cout << '\n';
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
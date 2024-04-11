#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, k;

    cin >> n >> k;

    if(k > n * n) {
        cout << "-1\n";
        return 0;
    }

    vec< vec< int > > a(n, vec< int >(n));

    for(int i = 0;i < n;i++) {
        if(n - i + n - i - 1 <= k) {
            k -= n - i + n - i - 1;
            for(int j = i;j < n;j++) {
                a[i][j] = a[j][i] = 1;
            }
        }else {
            for(int j = i;j < n;j++) {
                if(i == j) {
                    if(k > 0) {
                        k--;
                        a[i][i] = 1;
                    }
                }else {
                    if(k > 1) {
                        k -= 2;
                        a[i][j] = a[j][i] = 1;
                    }
                }
            }
            if(k > 0) {
                a[i + 1][i + 1] = 1;
            }
            break;
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
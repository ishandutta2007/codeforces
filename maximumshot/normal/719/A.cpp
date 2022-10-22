#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int arr[30] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

bool solve() {

    int n;
    cin >> n;
    vec< int > a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    int cn[2] = {0, 0};

    for(int d = 0;d < 30;d++) {
        int ok = 1;
        for(int i = 0;i < n;i++) {
            int j = (i + d) % 30;
            if(arr[j] != a[i]) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            int nx = (n + d) % 30;
            if(a[n - 1] < arr[nx]) cn[1]++;
            else cn[0]++;
        }
    }

    if(cn[0] > 0 && cn[1] > 0 || cn[0] == 0 && cn[1] == 0) {
        cout << "-1\n";
    }else if(cn[0] > 0) {
        cout << "DOWN\n";
    }else {
        cout << "UP\n";
    }

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}
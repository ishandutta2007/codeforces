#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    string s, t;

    cin >> s >> t;

    vec< int > way;
    int res = inf;

    for(int i = 0;i + n - 1 < m;i++) {
        vec< int > arr;
        for(int j = 0;j < n;j++) {
            if(s[j] != t[i + j]) {
                arr.push_back(j + 1);
            }
        }
        if((int)arr.size() < res) {
            res = (int)arr.size();
            way = arr;
        }
    }

    cout << res << "\n";

    for(int x : way) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}
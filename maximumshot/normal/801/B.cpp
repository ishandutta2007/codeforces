#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    string x, y;

    cin >> x >> y;

    for(int i = 0;i < (int)x.size();i++) {
        if(x[i] < y[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << y << "\n";

    return 0;
}
#include <bits/stdc++.h>

#include <time.h>
#include <random>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n, m;

    cin >> n >> m;

    char c;

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> c;
            if(c == 'C' || c == 'M' || c == 'Y') {
                cout << "#Color\n";
                return true;
            }
        }
    }

    cout << "#Black&White\n";

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
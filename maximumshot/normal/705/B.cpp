#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int res = 0;

    int n, x;
    cin >> n;

    for(int i = 0;i < n;i++) {
        cin >> x;
        if(x % 2 == 0) res ^= 1;
        cout << (res == 0?2 : 1) << '\n';
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}
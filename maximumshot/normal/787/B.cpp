#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, m;

    cin >> n >> m;

    for(int i = 0;i < m;i++) {
        set< int > q;
        int k;
        cin >> k;
        int ok = 1;
        for(int x, j = 0;j < k;j++) {
            cin >> x;
            if(q.count(-x)) ok = 0;
            q.insert(x);
        }
        if(ok) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
#include <bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;

const int max_n = 100111, inf = 1000111222;


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    int last = inf;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            swap(a, b);
        }
        if (a <= last) {
            last = a;
        } else if (b <= last) {
            last = b;
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

#include <iostream>

using namespace std;

int t, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for(int test = 0; test < t; test++) {
        cin >> n >> m;
        if(n == 1 || m == 1 || (n == 2 && m == 2)) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}
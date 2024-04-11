
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
int t, n;
long long a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = (((i + a[i]) % n) + n) % n;
        }
        sort(a, a + n);
        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(a[i] != i) {
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "YES\n";
        }
    }
}
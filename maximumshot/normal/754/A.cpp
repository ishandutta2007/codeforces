#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pii;

int main() {

    int n;
    cin >> n;

    int tot = 0;

    vector< int > a(n);

    int ok = 0;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        tot += a[i];
        if(a[i] != 0) {
            ok = 1;
        }
    }

    if(tot != 0) {
        cout << "YES\n1\n1 " << n << "\n";
        return 0;
    }

    if(ok) {
        tot = 0;
        for(int i = 0;i < n;i++) {
            tot += a[i];
            if(tot != 0) {
                cout << "YES\n2\n1 " << i + 1 << "\n" << i + 2 << " " << n << "\n";
                return 0;
            }
        }
    }else {
        cout << "NO\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 2];
    for ( int i = 1; i <= n; i++) {
        a[i] = 0;
    }
    cout << "? ";
    for ( int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
    int ans1, ans2;
    cin >> ans1;
    cout << "? ";
    cout << 1;
    for ( int i = 2; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
    cin >> ans2;
    if ( ans1 < ans2) {
        int pos0 = 1;
        int l = 1;
        int r = n;
        while ( l < r) {
            int mid = (l + r) / 2;
            cout << "? ";
            for ( int i = 1; i < l; i++) {
                cout << a[i];
            }
            for ( int i = l; i <= mid; i++) {
                a[i] = 1 - a[i];
                cout << a[i];
            }
            for ( int i = mid + 1; i <= n; i++) {
                cout << a[i];
            }
            cout << endl;
            cin >> ans2;
            if ( a[r] == 0 ) {
                if ( ans2 == ans1 + mid - l + 1) {
                    l = mid + 1;
                    ans1 = ans2;
                }
                else {
                    r = mid;
                    ans1 = ans2;
                }
            }
            if ( a[r] == 1) {
                if ( ans1 == ans2 + mid - l + 1) {
                    l = mid + 1;
                    ans1 = ans2;
                }
                else {
                    r = mid;
                    ans1 = ans2;
                }
            }
        }
        cout << "! " << 1 << " " << l << endl;
        return 0;
    }
    if ( ans1 > ans2) {
        int pos1 = 1;
        int l = 1;
        int r = n;
        while ( l < r) {
            int mid = (l + r) / 2;
            cout << "? ";
            for ( int i = 1; i < l; i++) {
                cout << a[i];
            }
            for ( int i = l; i <= mid; i++) {
                a[i] = 1 - a[i];
                cout << a[i];
            }
            for ( int i = mid + 1; i <= n; i++) {
                cout << a[i];
            }
            cout << endl;
            cin >> ans2;
            if ( a[r] == 1 ) {
                if ( ans2 == ans1 + mid - l + 1) {
                    l = mid + 1;
                    ans1 = ans2;
                }
                else {
                    r = mid;
                    ans1 = ans2;
                }
            }
            if ( a[r] == 0) {
                if ( ans1 == ans2 + mid - l + 1) {
                    l = mid + 1;
                    ans1 = ans2;
                }
                else {
                    r = mid;
                    ans1 = ans2;
                }
            }
        }
        cout << "! "<< l << " " << 1 << endl;
        return 0;
    }
    return 0;
}
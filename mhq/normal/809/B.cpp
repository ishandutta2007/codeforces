#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
    cin >> n >> k;
    int l = 1;
    int r = n;
    while (l != r) {
        int mid = (l + r) / 2;
        cout << 1 << " " << mid << " " << mid + 1 << endl;
        string s;
        cin >> s;
        if (s == "TAK") {
            r = mid;
        }
        else l = mid + 1;
    }
    int x1 = l;
    l = x1 + 1;
    r = n;
    if (l <= r) {
        while (l != r) {
            int mid = (l + r) / 2;
            cout << 1 << " " << mid << " " << mid + 1 << endl;
            string s;
            cin >> s;
            if (s == "TAK") {
                r = mid;
            }
            else l = mid + 1;
        }
        int x2 = l;
        cout << 1 << " " << x2 << " " << x1 << endl;
        string s;
        cin >> s;
        if (s == "TAK") {
            cout << 2 << " " << x1 << " " << x2 << endl;
            return 0;
        }
    }
    l = 1;
    r = x1 - 1;
    while (l != r) {
            int mid = (l + r) / 2;
            cout << 1 << " " << mid << " " << mid + 1 << endl;
            string s;
            cin >> s;
            if (s == "TAK") {
                r = mid;
            }
            else l = mid + 1;
        }
    int x2 = l;
    cout << 2 << " " << x2 << " " << x1 << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxN = (int)1e5 + 10;
int a[maxN];
int sgn(int x) {
    assert(x != 0);
    if (x > 0) return 1;
    else return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
 //   freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n;
    if (n % 4 == 2) {
        cout << "! -1" << endl;
        return 0;
    }
    int t = n / 2;
    cout << "? 1" << endl;
    cin >> a[1];
    cout << "? " << t + 1 << endl;
    cin >> a[t + 1];
    if (a[1] == a[t + 1]) {
        cout << "! 1" << endl;
        return 0;
    }
    int l = 1;
    int r = t + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        cin >> a[mid];
        cout << "? " << mid + t << endl;
        cin >> a[mid + t];
        if (a[mid] == a[mid + t]) {
            cout << "! " << mid << endl;
            return 0;
        }
        int sgn1 = sgn(a[l] - a[t + l]);
        int sgn2 = sgn(a[mid] - a[t + mid]);
        if (sgn1 != sgn2) r = mid;
        else l = mid;
    }
}
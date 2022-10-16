#include <iostream>
#include <vector>
#include <set>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t-->0) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;

        if (x + y <= e) {
            cout << x << " " << y << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <ios>

using namespace std;

int main() {
    ios :: sync_with_stdio(false);

    int a, b; cin >> a >> b;

    int ans = 0, num = 0;

    while (a > 0) {
        ans += a;
        num += a;
        a = num / b;
        num %= b;
    }

    cout << ans << endl;

    return 0;
}
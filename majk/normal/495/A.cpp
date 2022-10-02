#include <iostream>
#include <string>
using namespace std;

int main() {
    string S; cin >> S;
    int ans = 1;
    int r[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
    for (int c:S) {
        ans *= r[c-'0'];
    }
    cout << ans << endl;
}
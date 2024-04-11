#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;
    int ans = 0;
    for (char c:s) {
        ans *= 2;
        ans += c=='7';
    }

    for (int i = 1; i < s.size(); ++i) ans += 1<<i;
    cout << ans+1 << endl;
}
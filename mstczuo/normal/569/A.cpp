# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int main() {
    int T, S, q;
    cin >> T >> S >> q;
    int ans = 0;
    while(S < T) {
        S = S * q;
        ans += 1;
    }
    cout << ans << endl;
}
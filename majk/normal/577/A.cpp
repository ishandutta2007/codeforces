#include <iostream>

using namespace std;

int main() {
    int N, X; cin >> N >> X;
    int ans = 0;
    for (int i = 1; i * i <= X; ++i) {
        if (X%i != 0) continue;
        if (X/i <= N) {
            ++ans;
            if (i*i != X) ++ans;
        }
    }
    cout << ans << endl;
}
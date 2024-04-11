#include <iostream>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    if (A == B) {
        cout << "infinity\n";
    } else if (A < B) {
        cout << 0 << endl;
    } else {
        int C = A - B;
        int ans = 0;
        for (int i = 1; i*i <= C; ++i) {
            if (C%i == 0) {
                if (i > B) ++ans;
                if (i*i != C && C/i > B) ++ans;
            }
        }
        cout << ans << endl;
    }
}
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "YES\n";
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int e = abs(a)%2, f = abs(b)%2;
        cout << 1+e+f*2 << '\n';
    }
}
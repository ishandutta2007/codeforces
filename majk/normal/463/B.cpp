#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    int a = 0;
    for (int i = 0; i < N; ++i) {
        int h; cin >> h;
        a = max(a,h);
    }
    cout << a << endl;
}
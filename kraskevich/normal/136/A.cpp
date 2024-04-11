#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            p[--a] = i + 1;
    }
    for(int i = 0; i < n; ++i)
            cout << p[i] << " ";
    cin >> n;
    return 0;
}
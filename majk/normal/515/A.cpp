#include <iostream>

using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    if (abs(a) + abs(b) <= d && (d-abs(a)-abs(b))%2==0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
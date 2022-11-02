#include <bits/stdc++.h>

using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    int x = (a == 'a' || a == 'h' ? 2 : 3);
    int y = (b == '1' || b == '8' ? 2 : 3);
    cout << x * y - 1 << endl;
}
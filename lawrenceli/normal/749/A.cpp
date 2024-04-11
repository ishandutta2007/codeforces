#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n / 2 << endl;
    for (int i = 0; i < n / 2 - 1; i++) cout << "2 ";
    cout << (n % 2 ? "3\n" : "2\n");
}
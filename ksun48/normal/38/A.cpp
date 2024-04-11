#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    int a, b;
    for(int i = 1; i < n; i++) cin >> d[i];
    cin >> a >> b;
    int k = 0;
    for(int i = a; i < b; i++) k += d[i];
    cout << k << endl;
    return 0;
}
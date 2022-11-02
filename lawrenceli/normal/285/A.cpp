#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    for (int i=1; i<n-k; i++) cout << i << ' ';
    for (int i=n; i>=n-k; i--) {
        cout << i;
        if (i==n-k) cout << endl;
        else cout << ' ';
    }
}
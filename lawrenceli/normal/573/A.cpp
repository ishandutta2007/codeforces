#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100100];

int main() {
    int b = -1;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        while (a[i]%2 == 0) a[i] /= 2;
        while (a[i]%3 == 0) a[i] /= 3;
        if (b == -1) b = a[i];
        else if (b != a[i]) {
            cout << "No\n";
            return 0;
        }
    }
    
    cout << "Yes\n";
}
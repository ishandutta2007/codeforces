#include <iostream>
using namespace std;

const int MAX = 10000000;

int main() {
    int n;
    cin >> n;
    for (int i=MAX-n; i<MAX; i++) {
        cout << i;
        if (i<MAX-1) cout << ' ';
        else cout << endl;
    }
}
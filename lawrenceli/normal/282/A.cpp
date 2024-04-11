#include <iostream>
using namespace std;

int x, n;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        if (s=="++X" || s=="X++") x++;
        else x--;
    }
    cout << x << endl;
}
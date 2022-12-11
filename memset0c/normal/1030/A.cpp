#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x) {
            puts("HARD");
            return 0;
        }
    }
    puts("EASY");
    return 0;
}
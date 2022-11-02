#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) x++;
        else if (b > a) y++;
    }

    if (x > y) cout << "Mishka\n";
    else if (x < y) cout << "Chris\n";
    else cout << "Friendship is magic!^^\n";
}
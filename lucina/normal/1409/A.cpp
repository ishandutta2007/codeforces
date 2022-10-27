#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        int a, b;
        cin >> a >> b;
        int dif = abs(a - b);
        cout << (dif + 9) / 10 << '\n';
    }
}
/*
    I have been too lazy, lately.
*/
#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ;T -- ;) {
        int x;
        cin >> x;
        int bar = x % 10;
        string foo = to_string(x);
        cout << (bar - 1) * 10 + (foo.size() * (foo.size() + 1)) / 2 << '\n';
    }
}
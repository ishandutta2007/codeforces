
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    if(a + 1 == b) {
        cout << a << " " << b << endl;
    }else if(a == b) {
        cout << a << "0 " << b << 1 << endl;
    }else if(a == 9 && b == 1) {
        cout << "9 10" << endl;
    }else {
        cout << -1 << endl;
    }
}
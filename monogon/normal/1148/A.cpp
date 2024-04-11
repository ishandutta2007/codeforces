
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll a, b, c;

int main() {
    cin >> a >> b >> c;
    cout << (2 * c + min(a, b) + min(1 + min(a, b), max(a, b))) << endl;
}
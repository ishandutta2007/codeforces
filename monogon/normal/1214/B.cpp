
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int b, g, n;

int main() {
    ios::sync_with_stdio(false);
    cin >> b >> g >> n;
    cout << min(b, n) - n + min(g, n) + 1 << endl;
}
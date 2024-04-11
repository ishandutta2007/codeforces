
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int x;

int main() {
    ios::sync_with_stdio(false);
    cin >> x;
    if(x % 4 == 2) cout << "1 B" << endl;
    else cout << (((1 - x) % 4 + 4) % 4) << " A" << endl;
}
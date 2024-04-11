#include <bits/stdc++.h>
using namespace std;
string s, t;
vector < string > ans;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << (n / 2) * (n / 2 + 1);
    }
    else cout << (n + 1) /2  * (n + 1) / 2;
}
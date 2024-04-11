
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int x, y;

// b > a - y
// 2y + a > y + a
// increase small triangle until max side length = x

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y;
    vector<int> v = {y, y, y};
    int op = 0;
    while(v[0] != x) {
        v.erase(v.begin());
        v.push_back(min(x, v[0] + v[1] - 1));
        op++;
    }
    cout << op << endl;
}
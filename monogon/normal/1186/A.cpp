
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    cout << (m >= n && k >= n ? "Yes" : "No") << endl;
}
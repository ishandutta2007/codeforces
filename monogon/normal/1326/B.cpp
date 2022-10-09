
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll b[N], m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    m = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        cout << (m + b[i]) << " ";
        m = max(m, m + b[i]);
    }
    cout << endl;
}
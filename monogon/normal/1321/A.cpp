
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int n, a[N], b[N], A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        A += (a[i] && !b[i]);
        B += (!a[i] && b[i]);
    }
    cout << (A == 0 ? -1 : B / A + 1) << endl;
}
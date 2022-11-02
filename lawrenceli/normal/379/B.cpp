#include <cstdio>
#include <iostream>
#include <ios>

using namespace std;

const int MAXN = 305;

int n, a[MAXN];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n; i++) {
        if (i < n-1) {
            for (int j=0; j<a[i]; j++) {
                cout << "PRL";
            }
            cout << "R";
        } else {
            for (int j=0; j<a[i]; j++) {
                cout << "PLR";
            }
        }
    }

    return 0;
}
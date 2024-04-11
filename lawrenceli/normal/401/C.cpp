#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 1000100;

int n, m;
int arr[MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=1; m; i=(i+1)%(n+1), m--) arr[i]++;
    for (int i=0; i<n+1; i++)
        if (i != 0 && i != n && arr[i] == 0 || arr[i] >= 3) {
            cout << "-1\n";
            return 0;
        }

    for (int i=0; i<n+1; i++) {
        for (int j=0; j<arr[i]; j++) cout << '1';
        if (i<n) cout << '0';
    }

    return 0;
}
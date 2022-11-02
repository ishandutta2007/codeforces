#include <bits/stdc++.h>
using namespace std;

int n, a[2005];

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) {
        int k = 0;
        for (int j=0; j<n; j++)
            if (a[j] > a[i]) k++;
        cout << k+1 << ' ';
    }
}
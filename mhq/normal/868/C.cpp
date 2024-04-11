#include <bits/stdc++.h>
using namespace std;
int a[100010][5];
int b[40];
int pow1[] = {1, 2, 4, 8, 16};
int main() {
 int n, k;
 cin >> n >> k;
 for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
        cin >> a[i][j];
    }
 }
 for (int i = 1; i <= n; i++) {
    int t = 0;
    for (int j = 1; j <= k; j++) {
        t += a[i][j] * pow1[j - 1];
    }
    b[t]++;
 }
 for (int i = 0; i <= 20; i++) {
    for (int j = i + 1; j <= 20; j++) {
        if (b[i] > 0 && b[j] > 0) {
            if ((i & j) == 0) {
                cout << "YES";
                return 0;
            }
        }
    }
 }
 if (b[0] > 0) {cout << "YES"; return 0;}
 cout << "NO";
 return 0;
}
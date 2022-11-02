#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 300100;
const int maxk = 5005;

int n, k, a[maxn];
int dp[maxk][maxk];

void setmax(int& x, int y) { if (x < y) x = y; }

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    a[n] = a[n-1];
    
    int n1, n2, m1, m2;
    n1 = n%k, m1 = n/k+1;
    n2 = k-(n%k), m2 = n/k;

    dp[0][0] = 0;
    for (int i=0; i<=n1; i++)
        for (int j=0; j<=n2; j++) {
            int p = m1*i+m2*j;
            if (i<n1) setmax(dp[i+1][j], dp[i][j]+a[p+m1]-a[p+m1-1]);
            if (j<n2) setmax(dp[i][j+1], dp[i][j]+a[p+m2]-a[p+m2-1]);
        }

    cout << a[n-1] - a[0] - dp[n1][n2] << '\n';
}
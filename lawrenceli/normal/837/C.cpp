#include <bits/stdc++.h>

using namespace std;

int n, a, b, x[105][2];

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) cin >> x[i][0] >> x[i][1];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    if (x[i][k] <= a && x[j][l] <= a && x[i][!k] <= b && x[j][!l] <= b && (x[i][k] + x[j][l] <= a || x[i][!k] + x[j][!l] <= b))
                        ans = max(ans, x[i][0] * x[i][1] + x[j][0] * x[j][1]);
    cout << ans;
}
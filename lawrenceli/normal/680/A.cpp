#include <bits/stdc++.h>

using namespace std;

int a[5];

int main() {
    int ans = 1e9, sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ans = sum;

    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
            if (a[i] == a[j]) {
                ans = min(ans, sum - 2 * a[i]);
                for (int k = j + 1; k < 5; k++)
                    if (a[i] == a[k])
                        ans = min(ans, sum - 3 * a[i]);
            }

    cout << ans << endl;
}
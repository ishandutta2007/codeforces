#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int answer = 0;
    for (int i = n; i > 1; i = (i + k - 1) / k)
        answer++;

    cout << answer << '\n';

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int x = i, y = j, c = 1;
            while (x / k != y / k) {
                x /= k;
                y /= k;
                c++;
            }
            cout << c << " \n"[i == n - 2 && j == n - 1];
        }
}
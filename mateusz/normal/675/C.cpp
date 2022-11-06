#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
long long tab[N];
map<long long, int> M;

int main() {

    cin >> n;
    long long sum = 0;
    int mostFrequent = 0;
    int times = -1;
    for (int i = 1; i <= n; i++) {
        cin >> tab[i];
        sum += tab[i];
        if (!M.count(sum)) {
            M[sum] = 1;
        } else {
            M[sum]++;
        }
        if (M[sum] > times) {
            times = M[sum];
            mostFrequent = sum;
        }
    }
    cout << n - times << endl;
//     for (int i = n + 1; i <= 2 * n; i++) {
//         tab[i] = tab[i - n];
//     }
//     sum = 0;
//     for (int i = 1; i <= n; i++) {
//         sum += tab[i];
//         if (sum == mostFrequent) {
//             int ans = 0;
//             for (int j = i + 1; j < i + 1 + n; j++) {
//                 if (tab[j] == 0) {
//                     continue;
//                 } else {
//                     ans++;
//                     tab[j + 1] += tab[j];
//                 }
//             }
//             cout << ans << endl;
//             return 0;
//         }
//     }

    return 0;
}
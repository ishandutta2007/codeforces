#include <iostream>

using namespace std;

bool prime[1005], good[1005];

int main() {
    int cnt = 0, n;
    cin >> n;
    for (int i=1; i<=n; i++) prime[i] = 1;
    for (int i=2; i<=n; i++)
        if (prime[i]) {
            for (int j=i; j<=n; j+=i) prime[j] = 0;
            for (int j=i; j<=n; j*=i) good[j] = 1, cnt++;
        }

    cout << cnt << '\n';
    for (int i=1; i<=n; i++)
        if (good[i]) cout << i << ' ';
}
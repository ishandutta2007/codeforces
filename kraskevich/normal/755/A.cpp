#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = (int)1e6 + 10;

bool p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    fill(p + 2, p + N, true);
    for (int i = 2; i < N; i++)
        if (p[i])
            for (int j = 2 * i; j < N; j += i)
                p[j] = false;
    int n;
    cin >> n;
    for (int m = 1; m <= 1000; m++) 
        if (!p[n * m + 1]) {
            cout << m << endl;
            return 0;
        }
}
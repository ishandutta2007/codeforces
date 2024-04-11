#include <bits/stdc++.h>
using namespace std;
int n;
long long t = 1;
int iter = 10;
long long a[(int)1e6 + 10];
long long b[(int)1e6 + 10];
long long gcd(long long a, long long b) {
    if (a == 0 || b == 0) return a + b;
    if (a > b) return gcd(a % b, b);
    else return gcd(b % a, a);
}
void solve (int p) {
    vector < pair < long long, int > > divisors;
    for (int i = 1; i <= n; i++) {
        b[i] = gcd(a[i], a[p]);
    }
    sort(b + 1, b + n + 1);
    long long cur = -1;
    vector < long long > divisors1;
    for (int i = 1; 1LL * i * i <= a[p]; i++) {
        if (a[p] % i == 0) {
            divisors1.push_back(i);
            if (1LL * i * i != a[p]) divisors1.push_back(a[p] / (1LL * i));
        }
    }
    sort(divisors1.begin(), divisors1.end());
    for (int i = n; i >= 1; i--) {
        if (b[i] == cur) {
            divisors[divisors.size() - 1].second++;
            continue;
        }
        else divisors.push_back(make_pair(b[i], 1));
        cur = b[i];
    }
    for (int i = divisors1.size() - 1; i >= 0; i--) {
        int calc = 0;
        for (int j = 0; j < divisors.size(); j++) {
            if (divisors[j].first % divisors1[i] == 0) calc += divisors[j].second;
        }
        if (calc >= (n + 1) / 2) {
                t = max(t, divisors1[i]);
                return ;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int q = 1;
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= iter; i++) {
        solve(((1LL * rand() * rand() * rand()) % n) + 1);
    }
    cout << t;
    return 0;
}
#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

bool is_prime(int a) {
    if (a < 2) return 0;
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int next_prime(int n) {
    for (int i = n; ;++i) {
        if (is_prime(i)) {
            return i;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        ans.emplace_back(i, (i + 1) % n);
    }
    int need = next_prime(n) - n;
    if (n / 2 < need) {
        exit(228);
    }
    for (int i = 0; i < need; ++i) {
        ans.emplace_back(i, n / 2 + i);
    }
    cout << ans.size() << endl;
    for (pair<int, int> p : ans) {
        printf("%d %d\n", p.F + 1, p.S + 1);
    }
    return 0;
}
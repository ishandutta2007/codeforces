#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

constexpr int ps = 100005, as = 100001;

int n, m, t;
int a[as];

int nei(int st1, int st2) {
    return st1 > st2? st1 - st2 == 1 || st1 - st2 == m: st2 - st1 == 1 || st2 - st1 == m;
}

int bad() {
    for (int i = 0; i < n * m; ++i) {
        if (i >= m && nei(a[i], a[i - m])) {
            return i - m;
        } else if (i % m >= 1 && nei(a[i], a[i - 1])) {
            return i - 1;
        }
    }
    return n * m;
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> m;
    if (max(n, m) <= 3 && min(n, m) < 3 && n * m != 1) {
        return cout << "NO\n", 0;
    }
    for (int i = 0; i < n * m; ++i) {
        a[i] = i + 1;
    }
    while ((t = bad()) < n * m) {
        random_shuffle(a + t, a + n * m);
    }
    cout << "YES\n";
    for (int i = 0; i < n * m; ++i) {
        cout << a[i] << (i % m == m - 1? '\n':' ');
    }
    return 0;
}
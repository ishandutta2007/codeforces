#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<pair<int, int> > ans;

bool is_prime(int a) {
    if (a == 1) return 0;
    if (a == 2 || a == 3) return 1;
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

const int border = 2001;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    if (m + 1 < n) {
        cout << "Impossible";
        return 0;
    }
    for (int i = 1; i + 1 <= n; ++i) {
        ans.PB(MP(i, i + 1));
    }
    int sum = 0;
    /*for (int i = 2; i <= 100000; ++i) {
        if (!is_prime(i)) continue;
        sum += (i - 1);
        if (sum >= 100000) {
            cout << sum << ' ' << i << endl;
            break;
        }
    }*/
    if (n >= border) {
        for (int i = 3; i <= n; ++i) {
            if (!is_prime(i)) continue;
            for (int j = 1; j + 1 < i; ++j) {
                ans.PB(MP(j, i));
            }
            if (ans.size() >= m) break;
        }
        if (ans.size() < m) {
            return 228;
        }
        cout << "Possible" << endl;
        for (int i = 0; i < m; ++i) {
            printf("%d %d\n", ans[i].F, ans[i].S);
        }
    } else {
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j + 1 < i; ++j) {
                if (__gcd(i, j) != 1) continue;
                ans.PB(MP(j, i));
            }
            if (ans.size() >= m) break;
        }
        if (ans.size() < m) {
            cout << "Impossible";
            return 0;
        }
        cout << "Possible" << endl;
        for (int i = 0; i < m; ++i) {
            printf("%d %d\n", ans[i].F, ans[i].S);
        }
    }



    return 0;
}
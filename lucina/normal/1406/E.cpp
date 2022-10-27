#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const int L = 1e5;
vector <int> primes;
bool is_prime[L + 5];
int expect[L + 5];
int n;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    fill(is_prime + 2, is_prime + L + 1, true);
    for (int i = 2 ; i <= L ; ++ i) {
        if (!is_prime[i]) continue;
        for (int j = i + i ; j <= L ; j += i)
            is_prime[j] = false;
    }

    cin >> n;
    vector <int> small, large;

    for (int i = 2 ; i <= n ; ++ i) {
        if (!is_prime[i]) continue;
        if (int64_t(i) * i <= n) small.push_back(i);
        else large.push_back(i);
    }

    int64_t ans = 1;
    for (int x : small) {
        int64_t cur = x;
        cout << "B " << x << endl;
        int buf;
        cin >> buf;

        while (true) {
            cout << "A " << cur << endl;
            int res;
            cin >> res;
            if (res > 0) {
                ans *= x;
            } else break;
            cur *= x;
            if (cur > n) break;
        }
    }

    const int BS = 100;
    /**
        This way you can ask in O(n + n / T + T)
        choose T = 100
    */

    cout << "A 1" << endl;
    int alive;
    cin >> alive;

    while (!large.empty()) {
        int m = large.size();
        int mid = m / 2;

        int out = 0;

        for (int j = mid ; j < m ; ++ j) {
            cout << "B " << large[j] << endl;
            int buf = 1;
            cin >> buf;
            out += buf;
        }
        int many_left;
        cout << "A 1" << endl;
        cin >> many_left;
        if (alive - out != many_left) {
            for (int j = mid ; j < m ; ++ j) {
                cout << "A " << large[j] << endl;
                int has;
                cin >> has;
                if (has > 0) {
                    ans *= large[j];
                    cout << "C " << ans << endl;
                    return 0;
                }
            }
        }
        alive = many_left;
        large.resize(mid);
    }

    cout << "C " << ans << endl;
}
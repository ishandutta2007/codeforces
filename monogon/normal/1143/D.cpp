
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define VI vector<int>

using namespace std;

// x, y = nk / gcd(nk, l)
// minimize and maximize the gcd of nk and l

LL n, k, a, b;

LL gcd(LL x, LL y) {
    LL r;
    do {
        r = x % y;
        x = y;
        y = r;
    }while(y != 0);
    return x;
}

// l = ls[i] + m k

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> k >> a >> b;
    LL ls[] = {abs(a - b), k + a + b, k - a - b};
    LL x = n * k, y = 1;
    FOR(i, 4) {
        for(LL m = 0; ls[i] + m * k <= n * k; m++) {
            if(ls[i] + m * k != 0) {
                LL val = n * k / gcd(n * k, ls[i] + m * k);
                x = min(x, val);
                y = max(y, val);
            }
        }
    }
    cout << x << " " << y << endl;
}
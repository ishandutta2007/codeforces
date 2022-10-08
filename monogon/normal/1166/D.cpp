
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

LL a, b, m;

int main() {
    std::ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        cin >> a >> b >> m;
        LL p = 1;
        if(a == b) {
            cout << "1 " << a << endl;
            continue;
        }
        FORK(n, 1, 50) {
            if(b < p * (a + 1)) break;
            if(p * (a + 1) <= b && b <= p * (a + m)) {
                cout << (n + 1) << " " << a << " ";
                vector<int> r(n);
                LL R = b / p - a;
                // cout << "R: " << R << ", ";
                r[n - 1] = 0;
                FOR(i, n - 1) {
                    r[n - i - 2] = ((b % p) >> i) & 1;
                    // cout << +r[n - i - 1] << " ";
                }
                LL term = a;
                LL sum = a;
                FOR(i, n) {
                    term = sum + R + r[i];
                    sum += term;
                    cout << term << " ";
                }
                goto outer;
            }
            p *= 2;
        }
        cout << -1;
        outer:
        cout << endl;
    }
}
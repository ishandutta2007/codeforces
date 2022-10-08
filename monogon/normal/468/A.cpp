
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

int n;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    if(n < 4) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if(n % 2 == 0) {
        for(int i = n; i > 4; i -= 2) {
            cout << i << " - " << (i - 1) << " = 1" << endl;
            cout << "1 * 1 = 1" << endl;
        }
        cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24" << endl;
    }else {
        for(int i = n; i > 5; i -= 2) {
            cout << i << " - " << (i - 1) << " = 1" << endl;
            cout << "1 * 1 = 1" << endl;
        }
        cout << "2 + 3 = 5\n5 - 1 = 4\n4 * 5 = 20\n20 + 4 = 24" << endl;
    }
}
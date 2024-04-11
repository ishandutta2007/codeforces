
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

LL n, k;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if(n > k * k - k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int count = 0;
    for(int i = 0; i < 2 * k - 1; i++) {
        for(int b = 0; b < k; b++) {
            int g = i - b;
            if(b != g && g >= 0 && g < k) {
                count++;
                cout << (b + 1) << " " << (g + 1) << endl;
                if(count == n) return 0;
            }
        }
    }
}
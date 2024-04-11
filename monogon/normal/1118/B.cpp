
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

// store prefix sums for odd candies and even candies
// evens and odds switch after the ith candy

int n;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    VI a(n);
    VI even(n + 1);
    VI odd(n + 1);
    int e = 0, o = 0;
    FOR(i, n) {
        cin >> a[i];
        if(i % 2 == 0) {
            e += a[i];
        }else {
            o += a[i];
        }
        even[i + 1] = e;
        odd[i + 1] = o;
    }
    int sum = 0;
    FOR(i, n) {
        if(even[i] + (o - odd[i + 1]) == odd[i] + (e - even[i + 1])) {
            sum++;
        }
    }
    cout << sum << endl;
}

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

int n, k;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        if(k == 1 && i > 0) {
            cout << 0;
        }else {
            cout << (i % (1 + ((n - k) / 2)) == 0 ? "1" : "0");
        }
    }
    cout << endl;
}
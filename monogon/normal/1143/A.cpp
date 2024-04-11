
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

int n, a;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    int last0 = -1, last1 = -1;
    FOR(i, n) {
        cin >> a;
        if(a == 0) last0 = i;
        else last1 = i;
    }
    cout << min(last0 + 1, last1 + 1) << endl;
}
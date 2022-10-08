
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

const int MAX_N = 2e5 + 5;

int n, m;
LL a[MAX_N];

// 1 1 2 2 3
// 4 days:
// 1 / 2 3 / 2 / 1
// 1 3 / 1 / 2 / 2

// drink coffees spread out among the days
// drink them in decreasing order on a given day

bool check(int days) {
    int k = n - 1;
    int count = 0;
    int it = 0;
    while(k >= 0) {
        FOR(i, days) {
            count += max(a[k] - it, (LL) 0);
            k--;
            if(k < 0) break;
        }
        it++;
    }
    return count >= m;
}

int search(int l, int r) {
    if(l == r) return l;
    if(l + 1 == r) return (check(l) ? l : r);
    int m = (l + r) / 2;
    if(check(m)) {
        return search(l, m);
    }else {
        return search(m + 1, r);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    LL sum = 0;
    FOR(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum < m) {
        cout << -1 << endl;
        return 0;
    }
    sort(a, a + n);
    cout << search(1, sum) << endl;
}
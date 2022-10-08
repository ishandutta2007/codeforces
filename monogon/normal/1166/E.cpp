
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

// if S subset T then lcm(S) <= lcm(T)
// if dora shops at S and T, then S and T are not disjoint.
// Otherwise lcm(S) > lcm(S') >= lcm(T) > lcm(T') >= lcm(S)

// suppose {S1, ..., Sm} are pairwise non-disjoint.
// can we construct integers?
// {1, 2}, {1, 3}, {2, 3}
// All stores represented, the assignment [2, 3, 5] works

// {1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}
// [2, 3, 5, 7] looks like it should work in general

int m, n, k, a;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> m >> n;
    vector<bool> v(n);
    vector<set<int> > s(m);
    fill(all(v), true);
    FOR(i, m) {
        cin >> k;
        FOR(j, k) {
            cin >> a;
            s[i].insert(a - 1);
        }
    }
    FOR(i, m) {
        FOR(j, i) {
            for(int val : s[i]) {
                if(s[j].count(val)) {
                    goto outer;
                }
            }
            cout << "impossible" << endl;
            return 0;
            outer:;
        }
    }
    cout << "possible" << endl;
}
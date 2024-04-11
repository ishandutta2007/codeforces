
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
#define ll long long
#define VI vector<int>

using namespace std;

int q;
string s;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> s;
        sort(s.begin(), s.end());
        for(int i = 1; i < (int) s.length(); i++) {
            if(s[i] != s[i - 1] + 1) {
                cout << "NO" << endl;
                goto outer;
            }
        }
        cout << "YES" << endl;
        outer:;
    }
}
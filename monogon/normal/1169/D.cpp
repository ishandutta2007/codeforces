
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

string s;
int n;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    int l = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 2; j < 10 && i + j < n; j++) {
            for(int k = 1; j - 2 * k >= 0 && k < 10; k++) {
                if(s[i + j] == s[i + j - k] && s[i + j] == s[i + j - 2 * k]) {
                    sum += (i - l + 1) * (n - (i + j));
                    l = i + 1;
                    break;
                }
            }
        }
    }
    cout << sum << endl;
}
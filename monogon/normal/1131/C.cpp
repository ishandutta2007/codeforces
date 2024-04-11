
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

int n;
ll a[100];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    FOR(i, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << a[0] << " ";
    for(int i = 1; i < n - 1; i += 2) {
        cout << a[i] << " ";
    }
    cout << a[n - 1] << " ";
    for(int i = n - 2 - (n - 2) % 2; i > 0; i -= 2) {
        cout << a[i] << " ";
    }
    cout << endl;
}
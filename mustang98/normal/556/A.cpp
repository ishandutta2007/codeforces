#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 10000, inf = 1000111222;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    sort(s.begin(), s.end());
    int c0 = lower_bound(s.begin(), s.end(), '1') - s.begin();
    int c1 = n - c0;
    cout << max(c0, c1) - min(c0, c1) << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int k;
    cin >> k;

    string s;

    cin >> s;

    int sum = 0;

    for(char c : s) {
        sum += c - '0';
    }

    vec< int > arr;
    for(int i = 0;i < (int)s.size();i++) {
        int x = s[i] - '0';
        int mx = -inf;
        for(int y = i == 0;y < 10;y++) {
            mx = max(mx, y - x);
        }
        arr.push_back(mx);
    }
    sort(arr.rbegin(), arr.rend());
    int res = 0;
    for(int x : arr) {
        if(sum >= k) break;
        res++;
        sum += x;
    }
    cout << res << "\n";

    return 0;
}
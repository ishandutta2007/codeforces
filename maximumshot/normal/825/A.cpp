#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    string s;

    cin >> s;

    vec< int > arr;

    for(int i = 0;i < n;i++) {
        if(s[i] == '0') {
            arr.push_back(i);
        }
    }

    if(arr.empty()) {
        cout << n << "\n";
    }else {
        cout << arr.front();
        for(int i = 1;i < (int)arr.size();i++) {
            cout << arr[i] - arr[i - 1] - 1;
        }
        cout << n - 1 - arr.back() << "\n";
    }

    return 0;
}
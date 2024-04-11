#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, a, b, k;

    cin >> n >> a >> b >> k;

    string s;
    cin >> s;

    vec< int > res;

    for(int i = 0;i < n;i++) {
        if(s[i] == '1') continue;
        int j = i;
        while(j < n && s[j] == '0') j++; j--;
        // i .. j
        for(int q = i + b - 1;q <= j;q += b) res.push_back(q + 1);
        i = j;
    }

    for(int i = 0;i < a - 1;i++) res.pop_back();

    cout << (int)res.size() << "\n";

    for(int x : res) cout << x << ' ';
    cout << "\n";

    return 0;
}
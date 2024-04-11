#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

vector<int> m;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        m.PB(a);
    }
    sort(m.begin(), m.end());
    if(k == n) {
        cout << m[n - 1];
        return 0;
    }
    if (k == 0) {
        if (m[0] == 1) {
            cout << -1;
            return 0;
        }
        cout << m[0] - 1;
        return 0;
    }
    if (m[k - 1] != m[k]) {
        cout << m[k - 1];
    } else {
        cout << -1;
    }

    return 0;
}
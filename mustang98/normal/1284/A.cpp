#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100, inf = 1000111222;

vector<string> a, b;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q, y;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a.PB(s);
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        b.PB(s);
    }
    cin >> q;
    while(q--) {
        int y;
        cin >> y;
        --y;
        cout << a[y % n] << b[y % m] << "\n";
    }

    return 0;
}
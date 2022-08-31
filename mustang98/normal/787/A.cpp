#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100000, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    set<int> s;
    for (int i = 0; i < max_n; ++i) {
        s.insert(b + a * i);
    }
    for (int i = 0; i < max_n; ++i) {
        if (s.count(d + c * i)) {
            cout << d + c * i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
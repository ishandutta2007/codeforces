#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int c1= 0, c2 = 0;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            ++c1;
        } else {
            ++c2;
        }
    }
    if (c1 == 0) {
        for (int i = 0; i < n; ++i) {
            cout << 2 << ' ';
        }
        cout << endl;
        return 0;
    }
    if (c2 == 0) {
        for (int i = 0; i < n; ++i) {
            cout << 1 << ' ';
        }
        cout << endl;
        return 0;
    }
    cout << 2 << ' ' << 1 << ' ';
    --c1;
    --c2;
    for (int i = 0; i < c2; ++i) {
        cout << 2 << ' ';
    }
    for (int i = 0; i < c1; ++i) {
        cout << 1 << ' ';
    }
    return 0;
}
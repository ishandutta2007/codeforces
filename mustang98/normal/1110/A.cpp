#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int b, k;
    cin >> b >> k;
    for (int i = 0; i < k; ++i) {
        cin >> m[i];
    }
    int ans = 0;
    int p = 1;
    for (int i = k - 1; i >= 0; --i) {
        ans += (m[i] * p);
        p *= b;
        p %= 2;
        ans %= 2;
    }
    if (ans) {
        cout << "odd" << endl;
    } else {
        cout << "even";
    }

    return 0;
}
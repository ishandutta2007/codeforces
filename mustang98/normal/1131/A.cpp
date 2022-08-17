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

int main()
{
    //freopen("input.txt", "r", stdin);
    long long w1, w2, h1, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    long long ans = h1 * 2 + h2 * 2 + w1 + w2 + 4 + w1 - w2;
    cout << ans;

    return 0;
}
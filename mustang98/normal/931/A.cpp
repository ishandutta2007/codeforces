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
    int a, b;
    cin >> a >> b;
    int dist1 = abs(b - a) / 2;
    int dist2 = abs(b - a) - dist1;
    cout << (1LL * dist1 * (dist1 + 1) / 2 + 1LL * dist2 * (dist2 + 1) / 2);
    return 0;
}
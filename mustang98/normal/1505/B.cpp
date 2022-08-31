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
    ll a;
    cin >> a;
    ll result = a % 9;
    if (result == 0) {
        result = 9;
    }
    cout << result << endl;
    return 0;
}
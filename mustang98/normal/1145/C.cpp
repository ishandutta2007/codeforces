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
    int a;
    cin >> a;
    if (a == 3) {
        cout << 13;
        return 0;
    }
    if (a == 0) {
        cout << 15;
        return 0;
    }
    if (a == 1) {
        cout << 14;
        return 0;
    }
    if (a == 2) {
        cout << 12;
        return 0;
    }
    if (a == 4) {
        cout << 8;
        return 0;
    }
    if (a == 5) {
        cout << 9;
        return 0;
    }
    if (a == 6) {
        cout << 10;
        return 0;
    }
    if (a == 7) {
        cout << 11;
        return 0;
    }
    if (a == 8) cout << 0;
    else if (a == 9) cout << 1;
    else if (a == 10) cout << 2;
    else if (a == 11) cout << 3;
    else if (a == 12) cout << 4;
    else if (a == 13) cout << 5;
    else if (a == 14) cout << 6;
    else if (a == 15) cout << 7;
    while(1.0 * clock() / CLOCKS_PER_SEC < 0.05 * a) {
    }
    return 0;
}
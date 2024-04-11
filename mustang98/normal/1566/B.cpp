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
int c0 = 0, c1 = 0;
string s;

bool can0() {
    return (c0 == 0);
}

bool can1() {
    if (c1 == 0) {
        return true;
    }
    int a = -1, b = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (a == -1) a = i;
            b = i;
        }
    }
    return (b - a + 1) == c0;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        c0 = 0;
        c1 = 0;
        cin >> s;
        for (char c : s) {
            if (c == '0') ++c0;
            else ++c1;
        }
        if (can0()) {
            puts("0");
        } else if (can1()) {
            puts("1");
        } else {
            puts("2");
        }
    }

    return 0;
}
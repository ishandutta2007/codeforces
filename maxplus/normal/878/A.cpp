#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()

using namespace std;

constexpr int msk = 1023;

struct cmd {
    char t;
    short arg;
    short operator ()(short arg) {
        if (t == '&')
            return arg & this->arg;
        else if (t == '|')
            return arg | this->arg;
        else if (t == '^')
            return arg ^ this->arg;
    }
};

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    short x = 0, y = msk;
    cmd c;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c.t >> c.arg,
        x = c(x), y = c(y);
    int A = msk, X = 0, O = 0;
    for (int b = 1; b <= msk; b <<= 1)
        switch (!!(b & x) * 2 + !!(b & y)) {
            case 0:
                A ^= b;
                break;
            case 2:
                X ^= b;
                break;
            case 3:
                O ^= b;
                break;
        }
    cout << 3 << "\n& " << A << "\n^ " << X << "\n| " << O << '\n';
    return 0;
}
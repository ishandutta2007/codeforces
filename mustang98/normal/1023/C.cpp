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

int n, k;
string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    cin >> s;
    k /= 2;
    int cnto = 0;
    for (int i = 0; i < n; ++i) {
        if (k == 0) {
            break;
        }
        if (s[i] == '(' && k) {
            cout << "(";
            ++cnto;
            --k;
        } else {
            if (cnto) {
                --cnto;
                cout << ")";
            }
        }
    }
    for (int j = 0; j < cnto; ++j) {
        cout << ")";
    }
    return 0;

    return 0;
}
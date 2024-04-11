#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

string a, b;
int k;
int f[2], nf[2];
int res;

int main()
{
    getline(cin, a); getline(cin, b);
    cin >> k;
    f[0] = 1;
    while (k--) {
        nf[0] = ll(a.length() - 1) * ll(f[1]) % ll(mod);
        nf[1] = (f[0] + ll(a.length() - 2) * ll(f[1]) % ll(mod)) % ll(mod);
        f[0] = nf[0]; f[1] = nf[1];
    }
    if (a == b) res = f[0];
    for (int i = 1; i < a.length(); i++) {
        int j = 0;
        while (j < a.length() && a[j] == b[(i + j) % b.length()]) j++;
        if (j == a.length()) res = (res + f[1]) % mod;
    }
    cout << res << endl;
    return 0;
}
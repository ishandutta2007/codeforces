#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ios>

using namespace std;

const int maxn = 2000100;

int n;
char s[maxn];
int z[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> s[i];
        if (s[i] == 'N') s[i] = 'S';
        else if (s[i] == 'E') s[i] = 'W';
        else if (s[i] == 'S') s[i] = 'N';
        else s[i] = 'E';
    }

    for (int i = n-1; i < 2*n-2; i++) cin >> s[i];

    reverse(s, s + n - 1);

    n = 2 * n - 2;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (z[i - l] + i < r) z[i] = z[i - l];
        else {
            l = i;
            r = max(r, i);
            while (r < n && s[r] == s[r - l]) r++;
            z[i] = r - l;
        }
    }

    //for (int i = 0; i < n; i++) cout << z[i] << endl;

    for (int i = n / 2; i < n; i++)
        if (z[i] >= n - i) {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";
}
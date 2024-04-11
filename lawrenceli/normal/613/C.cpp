#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cassert>

using namespace std;

const int maxn = 100100;

int n;
int freq[30];

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    int g = 0, k = -1, b = 0;
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
        g = gcd(g, freq[i]);
        if (freq[i] & 1) {
            if (k == -1) k = i;
            else b = 1;
        }
    }

    if (b) {
        cout << "0\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < freq[i]; j++)
                cout << char('a' + i);
        return 0;
    }

    if (n == 1) {
        cout << freq[0] << '\n';
        for (int i = 0; i < freq[0]; i++) cout << 'a';
        return 0;
    }

    if (k != -1) {
        freq[k] -= g;
        string s = "";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < freq[i] / (2 * g); j++)
                s += 'a' + i;

        string t = s; reverse(t.begin(), t.end());
        s = char('a' + k) + s;
        s += t;
        cout << g << '\n';
        for (int i = 0; i < g; i++) cout << s;
    } else {
        assert(freq[0] > 0 && freq[0] % g == 0);
        assert(freq[1] > 0 && freq[1] % g == 0);
        freq[0] -= g, freq[1] -= g;
        string s = "";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < freq[i] / g; j++)
                s += 'a' + i;
        string t = s; reverse(t.begin(), t.end());
        s = "aa" + s + "bb" + t;
        cout << g << '\n';
        for (int i = 0; i < g / 2; i++) cout << s;
    }
}
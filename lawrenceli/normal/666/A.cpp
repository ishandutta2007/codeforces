#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <ios>
#include <set>

using namespace std;

const int maxn = 10100;

int n;
string s;
bool good[maxn][2];

bool eq(int a, int b) {
    for (int i = 0; i < b - a; i++)
        if (s[i + a] != s[i + b])
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> s;
    n = s.length();

    for (int i = 2; i <= 3; i++)
        good[n - i][i - 2] = 1;

    for (int i = n - 3; i >= 0; i--)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                if (good[i + j + 2][k] && (j != k || s.substr(i, j + 2) != s.substr(i + j + 2, j + 2)))
                        good[i][j] = 1;

    set<string> st;
    for (int i = 5; i < n; i++)
        for (int j = 0; j < 2; j++)
            if (good[i][j])
                st.insert(s.substr(i, j + 2));

    cout << st.size() << '\n';
    for (string x : st) cout << x << '\n';
}
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

char other(char c) {
    return c == '0' ? '1' : '0';
}

void finish(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.') {
            s[i] = '1';
        }
    }
    cout << s;
    exit(0);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, p;
    cin >> n >> p;
    if (n == p) {
        cout << "No";
        return 0;
    }
    string s;
    cin >> s;

    for (int i = 0; i + p < s.size(); ++i) {
        if (s[i] == '.' && s[i + p] == '.') {
            s[i] = '1';
            s[i + p] = '0';
            finish(s);
        }
        if (s[i] == '.') {
            s[i] = other(s[i + p]);
            finish(s);
        }
        if (s[i + p] == '.') {
            s[i + p] = other(s[i]);
            finish(s);
        }
        if (s[i] != s[i + p]) {
            finish(s);
        }
    }
    cout << "No";
    return 0;
}
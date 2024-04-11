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

bool check(string s) {
    int val = 0;
    for (char c : s) {
        if (c == '(') {
            ++val;
        } else {
            --val;
        }
        if (val < 0) {
            return false;
        }
    }
    if (val != 0) return false;
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        int n;
    cin >> n;
        string s;
        cin >> s;
        string a, b;
        int c0 = 0;
        for (char c : s) {
            if (c == '0') {
                ++c0;
            }
        }
        if (c0 % 2) {
            puts("NO");
            continue;
        }
        int k = (s.size() - c0) / 2;
        int cur = 0;
        bool isa = true;
        for (char c : s) {
            if (c == '0') {
                if (isa) {
                    a += '(';
                    b += ')';
                } else {
                    a += ')';
                    b += '(';
                }
                isa = !isa;
            } else {
                if (cur < k) {
                    a += '(';
                    b += '(';
                } else {
                    a += ')';
                    b += ')';
                }
                ++cur;
            }
        }
        if (check(a) && check(b)) {
            puts("YES");
            cout << a << "\n";
            cout << b << "\n";
        } else {
            puts("NO");
        }
    }

    return 0;
}
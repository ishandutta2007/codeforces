#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    int cz = 0;
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n ;++i) {
        if (s[i] == 'z') {
            ++cz;
        }
    }
    int c0 = cz;
    int c = s.size();
    c -= cz * 4;
    if (c % 3) {
        exit(228);
    }
    int c1 = c / 3;
    for (int i = 0; i < c1; ++i) {
        cout << 1 << ' ';
    }
    for (int i = 0; i < c0; ++i) {
        cout << 0 << ' ';
    }

    return 0;
}
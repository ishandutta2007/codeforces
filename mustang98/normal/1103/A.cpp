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

int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int j1 = 1;
    int j2 = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            cout << 3 << ' ' << j2 << "\n";
            ++j2;
            if (j2 == 5) j2 = 1;
        } else {
            cout << 1 << ' ' << j1 << "\n";
            j1 += 2;
            if (j1 == 5) j1 = 1;
        }
    }

    return 0;
}
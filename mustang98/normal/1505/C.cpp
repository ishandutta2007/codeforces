#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    vector<int> v;
    string s;
    cin >> s;
    for (char c : s) {
        v.PB(c - 'A');
    }
    bool ok = true;
    for (int i = 2; i < v.size(); ++i) {
        if (v[i] != (v[i - 1] + v[i - 2]) % 26) {
            ok = false;
            break;
        }
    }
    if (ok) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
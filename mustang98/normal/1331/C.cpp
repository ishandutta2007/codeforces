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
    //freopen("output.txt", "w", stdout);
    string s;
    int a;
    cin >> a;
    while(a) {
        s += ('0' + (a % 2));
        a /= 2;
    }
    reverse(s.begin(), s.end());
    while(s.size() < 6) {
        s = '0' + s;
    }
    s = '0' + s;
    string s1 = s;
    s1[1] = s[1];
    s1[2] = s[6];
    s1[3] = s[4];
    s1[4] = s[3];
    s1[5] = s[5];
    s1[6] = s[2];
    ll res = 0;
    for (char c : s1) {
        res = res * 2 + (c - '0');
    }
    cout << res << endl;

    return 0;
}
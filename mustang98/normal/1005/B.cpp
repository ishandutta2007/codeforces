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

string s1, s2;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int cnt = 0;
    for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
        if (s1[i] != s2[i]) break;
        cnt++;
    }
    ll ans = s1.size() + s2.size() - 2 * cnt;
    cout << ans;

    return 0;
}
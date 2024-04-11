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
    cin >> s;
    ll ans = 0;
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            ll curans = 0;
            ll ca = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == b) {
                    curans += ca;
                }
                if (s[i] == a) {
                    ++ca;
                }
            }
            ans = max(ans, curans);
            ans = max(ans, ca);
        }
    }
    cout << ans << endl;

    return 0;
}
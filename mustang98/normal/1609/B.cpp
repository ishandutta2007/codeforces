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
int n, q;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    cin >> s;
    int ans = 0;
    for (int i = 0; i + 2 < s.size(); ++i) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
            ++ans;
        }
    }
    while(q--) {
        int ind;
        char c;
        cin >> ind >> c;
        --ind;
        for (int i = max(0, ind - 5); i + 2 < min<int>(s.size(), ind + 10); ++i) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                --ans;
            }
        }
        s[ind] = c;
        for (int i = max(0, ind - 5); i + 2 < min<int>(s.size(), ind + 10); ++i) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                ++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
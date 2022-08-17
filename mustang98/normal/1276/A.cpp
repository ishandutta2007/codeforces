#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

string s;
char buf[max_n];


string read_str() {
    scanf("%s", buf);
    return buf;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        s = read_str();
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            if (i + 4 >= s.size()) {
                break;
            }
            if (s[i] == 't' &&
                s[i + 1] == 'w' &&
                s[i + 2] == 'o' &&
                s[i + 3] == 'n' &&
                s[i + 4] == 'e') {
                s[i + 2] = '.';
                ans.PB(i + 2);
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (i + 2 >= s.size()) {
                break;
            }
            if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
                ans.PB(i + 1);
                s[i + 1] = '.';
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (i + 2 >= s.size()) {
                break;
            }
            if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
                ans.PB(i + 1);
                s[i + 1] = '.';
            }
        }
        cout << ans.size() << "\n";
        for (int a : ans) {
            cout << a + 1 << ' ';
        }
        cout << "\n";
    }

    return 0;
}
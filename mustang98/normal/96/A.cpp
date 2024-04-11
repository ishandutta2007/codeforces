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
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            ++cnt;
        } else {
            if (cnt >= 7) {
                cout << "YES" << endl;
                return 0;
            }
            cnt = 1;
        }
    }
    if (cnt >= 7) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;

    return 0;
}
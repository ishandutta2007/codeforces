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
    for (int i = 0; i + 2 < s.size(); ++i) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            cout << "Yes";
            return 0;
        }
        if (s[i] == 'A' && s[i + 1] == 'C' && s[i + 2] == 'B') {
            cout << "Yes";
            return 0;
        }
        if (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'C') {
            cout << "Yes";
            return 0;
        }
        if (s[i] == 'B' && s[i + 1] == 'C' && s[i + 2] == 'A') {
            cout << "Yes";
            return 0;
        }
        if (s[i] == 'C' && s[i + 1] == 'A' && s[i + 2] == 'B') {
            cout << "Yes";
            return 0;
        }
        if (s[i] == 'C' && s[i + 1] == 'B' && s[i + 2] == 'A') {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";


    return 0;
}
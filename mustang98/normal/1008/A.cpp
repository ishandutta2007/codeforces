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
    set<char> sett;
    sett.insert('a');
    sett.insert('o');
    sett.insert('u');
    sett.insert('i');
    sett.insert('e');
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'n') continue;
        if (sett.count(s[i])) continue;
        if (i == s.size() - 1) {
            cout << "NO";
            return 0;
        }
        if (sett.count(s[i + 1]) == 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
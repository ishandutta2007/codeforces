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
    int cntb = 0, cntn = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'o') cntb++;
        else cntn++;
    }
    if (cntb == 0 || cntb == 1) {
        cout << "YES";
        return 0;
    }
    if (cntn % cntb == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const string f = "ACTG";

string s;

int distIn(int a, int b) { return b >= a? b - a: b - a + 26; }

int Dist(int a, int b)
{
    return min(distIn(a, b), distIn(b, a));
}

int main()
{
    int n; cin >> n;
    int res = 1000000000;
    cin >> s;
    for (int i = 0; i + 4 <= n; i++) {
        int cand = 0;
        for (int j = 0; j < 4; j++)
            cand += Dist(s[i + j] - 'A', f[j] - 'A');
        res = min(res, cand);
    }
    cout << res << endl;
    return 0;
}
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1;
    map<string, int> mm;
    for (int i = 0; i + 1 < s.size(); ++i) {
        s1 = "";
        s1 += s[i];
        s1 += s[i + 1];
        mm[s1]++;

    }
    string mx = "";
    int mcnt = -1;
    for (auto a : mm) {
        if (a.second > mcnt) {
            mcnt = a.S;
            mx = a.F;
        }
    }
    cout << mx;

    return 0;
}
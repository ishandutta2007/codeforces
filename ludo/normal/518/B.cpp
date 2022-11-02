#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

int scnt[52] = {}, tcnt[52] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    string s, t;
    cin >> s >> t;

    int ns = s.size(), nt = t.size();
    for (int i = 0; i < ns; i++) {
        if (s[i] <= 'Z' && s[i] >= 'A') scnt[s[i] - 'A' + 26]++;
        else scnt[s[i] - 'a']++;
    }
    for (int i = 0; i < nt; i++) {
        if (t[i] <= 'Z' && t[i] >= 'A') tcnt[t[i] - 'A' + 26]++;
        else tcnt[t[i] - 'a']++;
    }

    int y = 0, w = 0;
    for (int i = 0; i < 52; i++) {
        int d = min(scnt[i], tcnt[i]);
        y += d;
        scnt[i] -= d;
        tcnt[i] -= d;
    }

//    for (int i = 0; i < 52; i++) {
//        cerr << scnt[i] << " " << tcnt[i] << "\t";
//    }

    for (int i = 0; i < 26; i++) {
        int d = min(scnt[i], tcnt[i + 26]);
        w += d;
        scnt[i] -= d;
        tcnt[i + 26] -= d;
    }
    for (int i = 0; i < 26; i++) {
        int d = min(scnt[i + 26], tcnt[i]);
        w += d;
        scnt[i + 26] -= d;
        tcnt[i] -= d;
    }
    cout << y << endl << w << endl;
    return 0;
}
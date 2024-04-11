#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 5111, inf = 1000111222;

string s;
int cntb[max_n];
int cnta[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> s;
    int a=0, b=0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') ++a;
        else ++b;
        cntb[i] = b;
        cnta[i] = a;
    }

    int ans = max(cnta[s.size() - 1], cntb[s.size() - 1]);

    for (int l = 0; l < s.size(); ++l) {
        for (int r = l; r < s.size(); ++r) {
            if (s[l] != 'b' || s[r] != 'b') continue;
            int cur_ans = cnta[s.size() - 1] - cnta[r] + cnta[l] + cntb[r];
            if (l) cur_ans -= cntb[l - 1];
            ans = max(ans, cur_ans);
        }
    }
    cout << ans;
    return 0;
}
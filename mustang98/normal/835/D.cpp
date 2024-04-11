#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>
#include <unistd.h>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 5011, max_x = 101, max_c = 12, inf = 1000111222;

int ans[max_n][max_n];
int plen[max_n][2];

int globans[max_n];

int main()
{
    string s;
    cin >> s;
    for (int cen = 0; cen < s.size(); ++cen) {
        int i = 0;
        while (cen - i >= 0 && cen + i < s.size() && s[cen - i] == s[cen + i]) {
            ++i;
        }
        plen[cen][0] = i - 1;
    }

    for (int cen = 0; cen < s.size(); ++cen) {
        int i = 1;
        while (cen - i >= 0 && cen + i - 1 < s.size() && s[cen - i] == s[cen + i - 1]) {
            ++i;
        }
        plen[cen][1] = i - 1;

        //cout << plen[cen][1] << ' ';
    }
    //cout << endl;
    for (int i = 0; i < s.size(); ++i) {
        ans[i][i] = 1;
    }

    for (int len = 2; len <= s.size(); ++len) {
        for (int from = 0; from <= s.size() - len; ++from) {
            if (len % 2 == 0) {
                if (plen[from + len / 2][1] >= len / 2) ans[from][from + len - 1] = ans[from][from + len / 2 - 1] + 1;
                else ans[from][from + len - 1] = 0;
                globans[ ans[from][from + len - 1]]++;
            } else {
                if (plen[from + len / 2][0] >= len / 2) ans[from][from + len - 1] = ans[from][from + len / 2 - 1] + 1;
                else ans[from][from + len - 1] = 0;
                globans[ ans[from][from + len - 1]]++;
            }
        }
    }
   // cout << ans[1][2] << endl;
    globans[1] += s.size();
    //cout << globans[1] << endl;
    int ANS[max_n];
    for (int i = s.size(); i >= 0; --i) {
        if (i + 1 <= s.size()) ANS[i] = globans[i] + ANS[i + 1];
        else ANS[i] = globans[i];
    }
    for (int i = 1; i <= s.size(); ++i) {
        cout << ANS[i] << ' ';
    }
    return 0;

}
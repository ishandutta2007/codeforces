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

const int max_n = 100111, inf = 1000111222;

vector<int> ans;

ll val1[max_n];
int way[max_n];

void precalc() {
    val1[0] = inf;
    val1[1] = 1;
    val1[2] = 3;
    val1[3] = 4;
    way[1] = 1;
    way[2] = 1;
    way[3] = 2;

    for (int len = 4; len < max_n; ++len) {
        val1[len] = inf;

        for (int m = max(len / 2 - 10, 2); m < min(len - 1, len / 2 + 10); ++m) {
            int cur_a = val1[m - 1] + val1[len - m] + 2;
            if (val1[len] > cur_a) {
                val1[len] = cur_a;
                way[len] = m;
            }
        }
    }
}

vector<int> ans1;

void vosst(int l, int r) {
    if (r < l) return;
    int len = r - l + 1;
    if (len == 1) {
        ans.PB(l);
        return;
    }
    int m = way[len];
    ans.PB(l + m - 1);
    vosst(l, l + m - 2);
    vosst(l + m, r);
    ans.PB(l + m - 1);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    precalc();
    int n;
    cin >> n;
    vosst(1, n);
    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << ' ';
    }
    //cout << ans1.size() << ' ' << val[n] << endl;*/
    return 0;
}
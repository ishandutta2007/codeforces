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

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 1000111, inf = 1000111222, mod = 1000000007;
string s;


int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> s;
    ll cntb = 0;
    ll ans = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == 'a') {
            ans += cntb;
            cntb *= 2;
            ans %= mod;
            cntb %= mod;
        } else {
            cntb++;
        }
    }
    cout << ans;
    return 0;
}
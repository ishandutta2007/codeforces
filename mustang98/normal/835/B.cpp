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

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    ll k;
    string s;
    cin  >> k;
    cin >> s;
    sort(s.begin(), s.end());
    ll cursum = 0;
    for (char c : s) {
        cursum += (int) c - 48;
    }
    int cur = 0, ans = 0;
    while (cursum < k) {
        ans++;
        cursum += 9;
        cursum -= (s[cur] - 48);
        ++cur;
    }
    cout << ans;
    return 0;
}
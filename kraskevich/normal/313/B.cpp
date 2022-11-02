#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int N = 1000 * 1000;
int sum[N];
string s;
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> s;
    n = s.length();
    sum[0] = 0;
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1];
        if (s[i] == s[i - 1])
            sum[i]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << sum[r] - sum[l] << "\n";
    }


    return 0;
}
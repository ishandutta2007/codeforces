#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
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

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second

void openFiles()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}



void solve()
{
    string s = "0";
    string t;
    cin >> t;
    s += t;

    int n = s.length();
    string ns = "0";
    for (int i = 1; i < n; ++i)
        if (s[i] == '1')
            ns += '0';
        else
            ns += '1';
    int l = n - 1;
    while (ns[l] == '1')
        --l;
    ns[l] = '1';
    for (int i = l + 1; i < n; ++i)
        ns[i] = '0';

    //cerr << s << endl << ns << endl;

    int sumS = 0;
    int sumNs = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int s1;
        int s2;
        if (s[i] == '0')
            s1 = min(sumS, 1 + sumNs);
        else
            s1 = min(sumS + 1, 1 + sumNs);
        if (ns[i] == '0')
            s2 = min(sumNs, 1 + sumS);
        else
            s2 = min(sumNs + 1, 1 + sumS);
        sumS = s1;
        sumNs = s2;
    }
    cout << sumS;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //openFiles();


    solve();

    return 0;
}
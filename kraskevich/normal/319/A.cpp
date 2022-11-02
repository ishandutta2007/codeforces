#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <string.h>
#include <cctype>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;


//-----TEMPLATE STARTS HERE------//
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, long long> PIL;
typedef pair<long long, int> PLI;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef long double LD;

#define MP make_pair
#define PB push_back
#define hash __hash__
#define left __left__
#define right __right__
#define link __link__
#define div __div__
#define next __next__
#define y0 y1005000
#define y1 y1005001
#define F first
#define S second
//-----TEMPLATE ENDS HERE------//
//--ACTUAL SOLUTION IS BELOW---//

string bin(int x, int len)
{
    string res;
    for (int i = 0; i < len; i++)
        if (x & (1 << i))
            res = '1' + res;
        else
            res = '0' + res;
    return res;
}

int value(string s)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        res *= 2;
        res += s[i] - '0';
    }
    return res;
}

const int MOD = 1000 * 1000 * 1000 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    string s;
    cin >> s;
    int res = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        res *= 2;
        res += s[i] - '0';
        res %= MOD;
    }
    for (int i = 0; i < n - 1; i++)
        res = res * 2 % MOD;
    cout << res;

    return 0;
}
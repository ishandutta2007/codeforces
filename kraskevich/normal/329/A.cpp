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
//-----TEMPLATE ENDS HERE------//
//--ACTUAL SOLUTION IS BELOW---//


const int N = 111;
string s[N];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    VI p;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] == '.')
            {
                p.PB(j);
                break;
            }
    if (p.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << " " << p[i] + 1 << endl;
        }
        return 0;
    }
    p.clear();
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            if (s[i][j] == '.')
            {
                p.PB(i);
                break;
            }
    if (p.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << p[i] + 1 << " " << i + 1 << endl;
        }
        return 0;
    }
    cout << -1;

    return 0;
}
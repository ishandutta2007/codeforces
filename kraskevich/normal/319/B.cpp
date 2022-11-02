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

const int N = 100 * 1000 + 10;

int a[N];
set<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 0; i < n; i++)
        q.insert(i);
    set<int> all;
    for (int i = 0; i < n; i++)
        all.insert(i);
    for (;;)
    {
        bool any = false;
        vector<int> dead;
        set<int> qq;
        for (auto pos: q)
        {
            auto it = all.find(pos);
            if (it == all.end())
                continue;
            auto next = it;
            next++;
            if (next == all.end())
                continue;
            if (a[*it] > a[*next])
            {
                qq.insert(*it);
                dead.PB(*next);
            }
        }
        for (auto pos: dead)
            all.erase(pos);
        if (!dead.size())
            break;
        q = qq;
        res++;
    }
    cout << res;

    return 0;
}
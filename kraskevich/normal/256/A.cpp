#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>

using namespace std;

#define count cnt


const int B = 1000 * 1000 + 10;
vector<int> order[B];
const int N = 4000 + 10;
int values[N];

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
        order[values[i]].push_back(i);
    }

    int res = 0;
    for (int i = 0; i < B; ++i)
        res = max(res, (int)order[i].size());

    for (int start = 0; start < n; ++start)
    {
        for (int next = 0; next < n; ++next)
        {
            if (values[next] == values[start])
                continue;
            if (start != order[values[start]][0])
                continue;
            if (next != order[values[next]][0])
                continue;
            int ptrStart = 0;
            int ptrNext = -1;
            int takenNext = 0;
            int takenStart = 1;
            while (ptrStart < order[values[start]].size())
            {
                ++ptrNext;
                while (ptrNext < order[values[next]].size() && order[values[next]][ptrNext] < order[values[start]][ptrStart])
                    ++ptrNext;
                if (ptrNext == order[values[next]].size())
                    break;
                takenNext++;
                res = max(res, takenStart + takenNext);
                ++ptrStart;
                while (ptrStart < order[values[start]].size() && order[values[next]][ptrNext] > order[values[start]][ptrStart])
                    ++ptrStart;
                if (ptrStart == order[values[start]].size())
                    break;
                ++takenStart;
                res = max(res, takenStart + takenNext);

            }
        }
    }

    cout << res;

    return 0;
}
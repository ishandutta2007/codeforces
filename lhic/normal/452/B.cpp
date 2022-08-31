#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstring>

typedef long long ll;
typedef long double ld;

const int MAX_N = 110000;

using namespace std;


ld dist(pair<int, int> a, pair<int,int> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}


int n;

int m;

set<pair<int, int> > ss;
vector<pair<int, int> > vv;

int a1, a2, a3, a4;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = -3; i < 4; ++i)
        for (int j = -3; j < 4; ++j)
        {
            ss.insert({i, j});
            ss.insert({n + i, j});
            ss.insert({i, m + j});
            ss.insert({n + i, m + j});
        }

    for (auto x: ss)
    {
        if (!(x.first < 0 || x.first > n || x.second < 0 || x.second > m))
            vv.push_back(x);
    }
    ld ans = 0;
    for (int i = 0; i < vv.size(); ++i)
        for (int j = 0; j < vv.size(); ++j)
            for (int i1 = 0; i1 < vv.size(); ++i1)
                for (int j1 = 0; j1 < vv.size(); ++j1)
                {
                    if (i == j || i == i1 || i == j1 || j == i1 || j == j1 || i1 == j1)
                        continue;
                    if (dist(vv[i], vv[j]) + dist(vv[j], vv[i1]) + dist(vv[i1], vv[j1]) > ans)
                    {
                        ans = dist(vv[i], vv[j]) + dist(vv[j], vv[i1]) + dist(vv[i1], vv[j1]);
                        a1 = i;
                        a2 = j;
                        a3 = i1;
                        a4 = j1;
                    }
                }
    cout << vv[a1].first << " " << vv[a1].second << "\n";
    cout << vv[a2].first << " " << vv[a2].second << "\n";
    cout << vv[a3].first << " " << vv[a3].second << "\n";
    cout << vv[a4].first << " " << vv[a4].second << "\n";


    return 0;
}
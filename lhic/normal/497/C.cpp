#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>


using namespace std;

typedef long long ll;
typedef long double ld;

struct seg
{
    int a, b;
    int k;
    int t;
    int n;
};

bool cmp(seg a, seg b)
{
    if (a.a > b.a)
        return true;
    if (a.a < b.a)
        return false;
    return a.t < b.t;
}


set<pair<int, int> > ss;

vector<seg> vv;

int n, m;

int ans[120000];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {

        seg x;
        scanf("%d%d", &x.a, &x.b);
        x.n = i;
        x.t = 0;
        vv.push_back(x);
    }


    scanf("%d", &m);

    for (int i = 0; i < m; ++i)
    {
        seg x;
        scanf("%d%d%d", &x.a, &x.b, &x.k);

        x.n = i;
        x.t = 1;
        vv.push_back(x);
    }


    sort(vv.begin(), vv.end(), cmp);



    for (int i = 0; i < vv.size(); ++i)
    {
        if (vv[i].t == 0)
            ss.insert({vv[i].b, vv[i].n});
        else
        {
            if (ss.empty())
                continue;
            auto it = ss.upper_bound({vv[i].b + 1, -1});
            while (vv[i].k && !ss.empty() && it != ss.begin())
            {
                --it;
                ans[it->second] = vv[i].n;
                ss.erase(it);
                --vv[i].k;
                it = ss.upper_bound({vv[i].b + 1, -1});
            }
        }
    }

    if (!ss.empty())
    {
        cout << "NO";
        return 0;
    }

    printf("YES\n");

    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i] + 1);


    return 0;
}
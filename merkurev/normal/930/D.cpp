#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int X = (int) 2e5 + 100;
multiset <int> LD, LU, RD, RU;

const int OPEN_RD = 1;
const int OPEN_RU = 2;
const int CLOSE_LD = 3;
const int CLOSE_LU = 4;


struct Event
{
    int x, y, t;
    Event() : x(), y(), t() {}
    Event(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}

    bool operator < (const Event &A) const
    {
        if (x != A.x) return x < A.x;
        return t < A.t;
    }
};
vector <Event> events;

void addLD(int x, int y)
{
    LD.insert(y);
    events.emplace_back(x, y, CLOSE_LD);
}
void addLU(int x, int y)
{
    LU.insert(y);
    events.emplace_back(x, y, CLOSE_LU);
}
void addRD(int x, int y)
{
    events.emplace_back(x, y, OPEN_RD);
}
void addRU(int x, int y)
{
    events.emplace_back(x, y, OPEN_RU);
}
void clear()
{
    LD.clear();
    LU.clear();
    RD.clear();
    RU.clear();
    events.clear();
}

vector <pair <int, int> > v[2];

long long solve(int t)
{
    clear();
    long long ans = 0;

//    eprintf(">> %d\n", (int) v[t].size() );
    for (auto p : v[t] )
    {
        int x = p.first - p.second, y = p.first + p.second;
//        eprintf("x = %d, y = %d\n", x, y);
        addLD(x - 1, y - 1);
        addLU(x - 1, y + 1);
        addRD(x + 1, y - 1);
        addRU(x + 1, y + 1);
    }
//    eprintf("! %d\n", (int) events.size() );
    sort(events.begin(), events.end() );
    events.emplace_back(X + 1, 0, 0);
//    eprintf("!\n");
    int pos = 0;
    for (int i = -X; i <= X; i++)
    {
//        eprintf("i = %d, pos = %d\n", i, pos);
        while (events[pos].x == i && events[pos].t == OPEN_RD)
        {
            RD.insert(events[pos].y);
            pos++;
        }
        while (events[pos].x == i && events[pos].t == OPEN_RU)
        {
            RU.insert(events[pos].y);
            pos++;
        }

        if (!RD.empty() && !RU.empty() && !LD.empty() && !LU.empty() )
        {
            int l = max(*RU.begin(), *LU.begin() );
            int r = min(*RD.rbegin(), *LD.rbegin() );
            if (abs(i + l) % 2 == 1) l++;
            if (abs(i + r) % 2 == 1) r--;
            if (abs(i) % 2 != t && l <= r)
            {
                ans += (r - l) / 2 + 1;
            }
        }


        while (events[pos].x == i && events[pos].t == CLOSE_LD)
        {
            LD.erase(LD.find(events[pos].y) );
            pos++;
        }
        while (events[pos].x == i && events[pos].t == CLOSE_LU)
        {
            LU.erase(LU.find(events[pos].y) );
            pos++;
        }
    }
    return ans;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        v[abs(x + y) % 2].emplace_back(x, y);
    }
    long long ans = solve(0) + solve(1);
    printf("%lld\n", ans);

	return 0;
}
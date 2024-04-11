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


const int K = 3;
const int N = (int) 2e5 + 100;
int cnt[N][K][K];


int fn[N];

void add(int pos, int x)
{
    pos++;
    for (;pos < N; pos = (pos | (pos - 1) ) + 1)
        fn[pos] += x;
}
int sum(int pos)
{
    pos++;
    int ans = 0;
    for (; pos > 0; pos = (pos & (pos - 1) ) )
        ans += fn[pos];
    return ans;
}
int sum(int l, int r)
{
    return sum(r) - sum(l - 1);
}

struct Event
{
    int t, x, y1, y2, id, i, j;

    Event() : t(), x(), y1(), y2(), id(), i(), j() {}
    Event(int _t, int _x, int _y1, int _y2, int _id, int _i, int _j) : 
        t(_t), x(_x), y1(_y1), y2(_y2), id(_id), i(_i), j(_j) {}
    Event(int _t, int _x, int _y) :
        t(_t), x(_x), y1(_y), y2(_y), id(), i(), j() {}


    bool operator < (const Event &E) const
    {
        if (x != E.x) return x < E.x;
        return t < E.t;
    }
};

vector <Event> events;



void addPoint(int x, int y)
{
    events.push_back(Event(1, x, y) );
}

void addQ(int x, int y1, int y2, int id, int i, int j)
{
 //   eprintf("addQ : x = %d y1 = %d y2 = %d id = %d i = %d j = %d\n", x, y1, y2, id, i, j);
    events.push_back(Event(2, x, y1, y2, id, i, j) );
}

int n;

void addRect(int x1, int y1, int x2, int y2, int id)
{
    vector <pair <int, int> > segx = {{0, x1 - 1}, {x1, x2}, {x2 + 1, n + 1}};
    vector <pair <int, int> > segy = {{0, y1 - 1}, {y1, y2}, {y2 + 1, n + 1}};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            addQ(segx[i].second, segy[j].first, segy[j].second, id, i, j);
        }
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        int c = i;
        int r;
        scanf("%d", &r);
        addPoint(c, r);
    }
    for (int i = 0; i < q; i++)
    {
        int l, d, r, u;
        scanf("%d%d%d%d", &l, &d, &r, &u);
        addRect(l, d, r, u, i);
    }

    sort(events.begin(), events.end() ); 
    
    for (auto E : events)
    {
        if (E.t == 1)
        {
            add(E.y1, 1);
        }
        else
        {
            int x = sum(E.y1, E.y2);
            cnt[E.id][E.i][E.j] += x;
            if (E.i + 1 < 3)
                cnt[E.id][E.i + 1][E.j] -= x;
        }
    }
    for (int i = 0; i < q; i++)
    {
/*        for (int i1 = 0; i1 < 3; i1++)
        {
            for (int j1 = 0; j1 < 3; j1++)
                eprintf("%d ", cnt[i][i1][j1] );
            eprintf("\n");
        }
*/
        long long ans = 0;
        for (int i1 = 0; i1 < 3; i1++)
            for (int j1 = 0; j1 < 3; j1++)
                for (int i2 = 0; i2 < 3; i2++)
                    for (int j2 = 0; j2 < 3; j2++)
                    {
                        if (i1 == i2 && (i1 == 0 || i1 == 2) ) continue;
                        if (j1 == j2 && (j1 == 0 || j1 == 2) ) continue;
                        long long x = cnt[i][i1][j1] * 1LL * cnt[i][i2][j2];
                        if (i1 == i2 && j1 == j2)
                            x = cnt[i][i1][j1] * 1LL * (cnt[i][i1][j1] - 1);
                        ans += x;
                    }
        ans /= 2;
        printf("%lld\n", ans);
    }


	return 0;
}
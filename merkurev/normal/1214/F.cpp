#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif


const int N = (int) 4e5 + 100;
int a[N], b[N];

int d, n;

vector <pair <int, int>> ev;

void addEvent(int pos, int x)
{
    ev.emplace_back(pos, x);
}

void addSemi(int l, int r, int x)
{
    //eprintf("add [%d, %d) : %d\n", l, r, x);
    while (l > 0)
    {
        l -= n;
        r -= n;
    }
    while (r <= 0)
    {
        l += n;
        r += n;
    }
    while (l < n)
    {
        int cl = max(l, 0);
        int cr = min(r, n);
        //eprintf("[%d, %d) %d\n", cl, cr, x);
        addEvent(cl, x);
        addEvent(cr, -x);

        l += n;
        r += n;
    }
}

const long long INF = (long long) 1e18;

map <int, vector <int>> X, Y;

int getXID(int i)
{
    int ans = X[i].back();
    X[i].pop_back();
    return ans;
}

int getYID(int i)
{
    int ans = Y[i].back();
    Y[i].pop_back();
    return ans;
}

int answer[N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &d, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
        X[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        b[i]--;
        Y[b[i]].push_back(i);
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        a[n + i] = d + a[i];
        b[n + i] = d + b[i];
    }
    for (int i = 0; i < n; i++)
    {
        //eprintf("i = %d\n", i);
        int j1 = lower_bound(b, b + 2 * n, a[i]) - b;
        int j2 = lower_bound(b, b + 2 * n, a[i] + (d + 1) / 2) - b;
        int j3 = j1 + n;
        
        //eprintf("%d %d %d\n", j1, j2, j3);
        if (j2 > n)
        {
            addSemi(j1 - i, n - i, -a[i]);
            addSemi(n - i, j2 - i, d - a[i]);
            
            addSemi(j2 - i, j3 - i, a[i]);
        }
        else
        {
            addSemi(j1 - i, j2 - i, -a[i]);

            addSemi(j2 - i, n - i, d + a[i]);
            addSemi(n - i, j3 - i, a[i]);
        }
    }
    for (int j = 0; j < n; j++)
    {
        eprintf("j = %d\n", j);
        int i1 = lower_bound(a, a + 2 * n, b[j] + 1) - a;
        int x = (d + 1) / 2;
        if (d % 2 == 0)
            x++;
        int i2 = lower_bound(a, a + 2 * n, b[j] + x) - a;
        addSemi(j - i2 + 1, j - i1 + 1, -b[j]);
        int i3 = i1 + n;
        addSemi(j - i3 + 1, j - i2 + 1, b[j]);
    }

    long long sum = 0;
    pair <long long, int> ans = make_pair(INF, 0);
    int ppos = 0;
    sort(ev.begin(), ev.end());
    for (auto p : ev)
    {
        if (p.first > ppos)
            ans = min(ans, make_pair(sum, ppos));
        ppos = p.first;
        sum += p.second;
    }
    //ans = min(ans, sum);
    printf("%lld\n", ans.first);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int y = b[(ans.second + i) % n];
        answer[getXID(x)] = getYID(y);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i] + 1);


    return 0;
}
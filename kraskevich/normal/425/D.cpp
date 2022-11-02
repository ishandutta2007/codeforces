#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const int INF = (int)1e9;

const int N = 200 * 1000 + 10;
const int ADD = 100 * 1000 + 1;

const int SQRT = 333;

long long res = 0;
int n;
vector<pii> p;
vector<int> atY[N];
unordered_set<int> atX[N];
bool was[N];

bool good(int c)
{
    return c >= 0 && c < N;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int xx, yy;
        cin >> xx >> yy;
        int x = xx + yy;
        int y = xx - yy;
        y += ADD;
        //cerr << x << " " << y << endl;
        p.push_back(pii(x, y));
        atY[y].push_back(x);
        atX[x].insert(y);
    }
    for (int y = 0; y < N; y++)
        sort(atY[y].begin(), atY[y].end());

    for (int y = 0; y < N; y++)
    {
        if (atY[y].size() >= SQRT) //heavy line
        {
            fill(was, was + N, false);
            for (int i = 0; i < atY[y].size(); i++)
                was[atY[y][i]] = true;
            for (int i = 0; i < n; i++)
            {
                int xx = p[i].F;
                int yy = p[i].S;
                if (yy <= y)
                    continue;
                int d = yy - y;
                if (!good(xx - d) || !was[xx - d])
                    continue;
                if (!good(xx + d) || !was[xx + d])
                    continue;
                if (!atX[xx].count(yy - 2 * d))
                    continue;
                res++;
            }
        } else { // light line
            for (int i = 0; i < atY[y].size(); i++)
                for (int j = i + 1; j < atY[y].size(); j++)
                {
                    int x1 = atY[y][i];
                    int x2 = atY[y][j];
                    int d = x2 - x1;
                    if (d % 2)
                        continue;
                    d /= 2;
                    int x = (x1 + x2) / 2;
                    if (atX[x].count(y + d) && atX[x].count(y - d))
                        res++;
                }
        }
    }

    cout << res;

    return 0;
}
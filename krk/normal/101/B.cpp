#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
const int Maxm = 100005;
const int Maxn = 200015;

int n, m;
vector <int> stops;
pair <int, int> edge[Maxm];
int BIT[Maxn];

bool Less(const pair <int, int> &a, const pair <int, int> &b)
{
     if (a.second != b.second) return a.second < b.second;
     return a.first < b.first;
}

void Insert(int x, int val)
{
     x += 2;
     for (int i = x; i < Maxn; i += i & -i)
        BIT[i] = (BIT[i] + val) % mod;
}

int Get(int x)
{
    x += 2;
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
       res = (res + BIT[i]) % mod;
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    stops.push_back(0); stops.push_back(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edge[i].first, &edge[i].second);
        stops.push_back(edge[i].first); stops.push_back(edge[i].second);
    }
    sort(stops.begin(), stops.end());
    stops.erase(unique(stops.begin(), stops.end()), stops.end());
    for (int i = 0; i < m; i++) {
        int a = lower_bound(stops.begin(), stops.end(), edge[i].first) - stops.begin();
        int b = lower_bound(stops.begin(), stops.end(), edge[i].second) - stops.begin();
        edge[i] = make_pair(a, b);
    }
    int ind = lower_bound(stops.begin(), stops.end(), n) - stops.begin();
    n = ind;
    sort(edge, edge + m, Less);
    Insert(0, 1);
    for (int i = 0; i < m; i++) {
        int ways = Get(edge[i].second - 1) - Get(edge[i].first - 1);
        while (ways < 0) ways += mod;
        Insert(edge[i].second, ways);
    }
    int res = Get(n) - Get(n - 1);
    while (res < 0) res += mod;
    cout << res << endl;
    return 0;
}
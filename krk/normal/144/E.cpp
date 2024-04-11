#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define mp make_pair
using namespace std;

const int Maxn = 100005;

typedef pair <int, int> ii;

int n, m;
pair <ii, int> seg[Maxn];
priority_queue <ii> Q;
vector <int> res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int r, c; scanf("%d %d", &r, &c);
        seg[i].first.first = n - r + 1, seg[i].first.second = c;
        seg[i].second = i + 1;
    }
    sort(seg, seg + m);
    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j < m && seg[j].first.first == i) {
              Q.push(mp(-seg[j].first.second, seg[j].second));
              j++;
        }
        while (!Q.empty() && -Q.top().first < i) Q.pop();
        if (!Q.empty()) { res.push_back(Q.top().second); Q.pop(); }
    }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}
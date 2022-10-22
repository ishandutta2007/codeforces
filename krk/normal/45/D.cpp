#include <cstdio>
#include <queue>
#include <algorithm>
#define mp make_pair
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n;
ii seq[Maxn];
int ind[Maxn], res[Maxn];
priority_queue <ii> Q;

bool Less(const int &a, const int &b)
{
    return seq[a] < seq[b];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &seq[i].first, &seq[i].second);
        ind[i] = i;
    }
    sort(ind, ind + n, Less);
    int i = 0;
    for (int d = 1; d <= 10000000; d++) {
        while (i < n && seq[ind[i]].first == d) {
            Q.push(mp(-seq[ind[i]].second, ind[i]));
            i++;
        }
        if (!Q.empty()) {
            res[Q.top().second] = d; Q.pop();
        }
    }
    for (int i = 0; i < n; i++) printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}
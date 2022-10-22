#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> ii;

const int Maxn = 100005;

int n, m;
ll t[Maxn], x[Maxn];
ll T, X;
int wt;
vector <ii> inbus;
ll res[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%I64d %I64d", &t[i], &x[i]);
    while (wt < n) {
        while (wt < n && inbus.size() < m) {
            T = max(T, t[wt]);
            inbus.push_back(make_pair(x[wt], wt)); wt++;
        }
        sort(inbus.begin(), inbus.end());
        int j;
        for (int i = 0; i < inbus.size(); i = j) {
            T += inbus[i].first - X; X = inbus[i].first;
            j = i;
            while (j < inbus.size() && inbus[j].first == X) {
                res[inbus[j].second] = T; j++;
            }
            T += 1 + (j - i) / 2;
        }
        T += X; X = 0;
        inbus.clear();
    }
    for (int i = 0; i < n; i++) printf("%I64d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}
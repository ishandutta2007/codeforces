#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 4005;

int n;
int a[Maxn];
vector <int> seq;
vector <int> pl;
int best = Inf;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        double tmp; scanf("%lf", &tmp);
        a[i] = int(tmp * 1000.0l + 0.01) % 1000;
        if (a[i]) seq.push_back(a[i]);
    }
    sort(seq.begin(), seq.end());
    int lft = 2 * n - seq.size();
    pl.resize(seq.size());
    for (int i = seq.size() - 1; i >= 0; i--)
        pl[i] = (i == seq.size() - 1? 0: pl[i + 1]) + 1000 - seq[i];
    if (lft >= n) best = min(best, seq.size()? pl[0]: 0); 
    int sum = 0;
    for (int i = 0; i < seq.size(); i++) {
        sum += seq[i];
        if (i + 1 + lft >= n && i + 1 <= n) best = min(best, abs((i + 1 < seq.size()? pl[i + 1]: 0) - sum));
    }
    printf("%d.%03d\n", best / 1000, best % 1000);
    return 0;
}
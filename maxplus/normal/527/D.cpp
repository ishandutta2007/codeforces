#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define f first
#define s second

using namespace std;

vector<pair<int, int>> ev;
map<int, int> ans;
int x[200001], w[200001];

int main()
{
    int n, ANS = 0, am = 0, mg = 0, debug;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> w[i];
        ev.push_back({x[i] - w[i], i});
        ans[x[i] + w[i]];
    }
    sort(ev.begin(), ev.end());
    auto lm = ans.begin();
    for (int i = 0; i < ev.size(); ++i)
    {
        while (lm->f <= ev[i].f)
            mg = max(mg, lm->s), lm++;
        ans[debug = x[ev[i].s] + w[ev[i].s]] = max(ans[x[ev[i].s] + w[ev[i].s]], mg + 1);
    }
    while (lm != ans.end())
        mg = max(mg, lm->s), lm++;
    cout << mg;
    return 0;
}
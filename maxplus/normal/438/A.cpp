#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

const int N = 1000;

using namespace std;

struct part{
    vector<int> ced;
    int energy, rn;
};

bool comp(part a, part b)
{
    return a.energy < b.energy;
}

part srtd[N];
int energy[N];
int place[N];

int main()
{
    int t1, t2;
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> energy[i];
        srtd[i].energy = energy[i];
        srtd[i].rn = i;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> t1 >> t2;
        srtd[--t1].ced.push_back(--t2);
        srtd[t2].ced.push_back(t1);
    }
    sort(srtd, srtd + n, comp);
    for (int i = 0; i < n; ++i)
        place[srtd[i].rn] = i;
    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j < srtd[i].ced.size(); j++)
            ans += (energy[srtd[i].ced[j]]) * (place[srtd[i].ced[j]] < i);

    cout << '\n' << ans;
    return 0;
}
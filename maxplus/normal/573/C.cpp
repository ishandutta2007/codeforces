#include <iostream>
#include <cstring>
#include <vector>
#define pb push_back

using namespace std;

vector<int> nei[100001];
int tram[100001], tin[100001], t;

int count(int a)
{
    if (tram[a] != -1)
        return 0;
    tram[a] = 0;
    tin[a] = ++t;
    for (auto i: nei[a])
        tram[a] += count(i);
//    tout[a] = ++t;
    return tram[a] + (nei[a].size() >= 3);
}

int main()
{
    memset(tram, -1, sizeof(tram));
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; ++i)
        (cin >> a >> b), nei[--a].pb(--b), nei[b].pb(a);
    int full = count(0);
    for (int i = 0; i < n; ++i)
    {
        int am = 0;
        for (auto j: nei[i])
            if (nei[j].size() >= 4)
                am++;
            else if (tin[j] > tin[i] && tram[j])
                am++;
            else if (tin[j] < tin[i] && full - tram[i] - (nei[i].size() >= 3) - (nei[j].size() >= 3))
                am++;
        if (am >= 3)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
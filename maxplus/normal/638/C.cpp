#define first f
#define second s
#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

const int N = 200001;
int n, a, b, u[N];
vector<int> r[N];
vector<pair<int, int>> nei[N];

void paint(int v, int fc)
{
    u[v] = 1;
    int nc = 0;
    for (auto i: nei[v]) if (!u[i.f])
        nc += nc == fc, r[nc].pb(i.s), paint(i.f, nc), ++nc;
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> a >> b, nei[--a].pb({--b, i}), nei[b].pb({a, i});
    paint(0, -1);
    for (int i = 0; ; ++i)
        if (r[i].empty())
        {
            cout << i;
            break;
        }
    for (int i = 0; r[i].size(); ++i)
    {
        cout << '\n' << r[i].size();
        for (auto k: r[i])
            cout << ' ' << k;
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

const int N = 300005;

int n, a[N], pos[N];
vector<pair<int, int>> ve;

void make_move(int i, int j)
{
    swap(pos[a[i]], pos[a[j]]);
    swap(a[i], a[j]);
    ve.push_back({i, j});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i < n; i++)
    {
        while (pos[i] != i)
        {
            if (2 * abs(pos[i] - i) >= n)
                make_move(pos[i], i);
            else if (2 * abs(pos[i] - 1) >= n)
                make_move(pos[i], 1);
            else
                make_move(pos[i], n);
        }
        if (a[1] != 1)
            make_move(pos[1], 1);
    }
    cout << ve.size() << '\n';
    for (pair<int, int> &v : ve)
        cout << v.first << " " << v.second << '\n';
}
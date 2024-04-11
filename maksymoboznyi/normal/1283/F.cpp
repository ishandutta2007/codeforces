#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

set<int> s;
int n, p[N], par[N], used[N];



int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> p[i], s.insert(i);
    s.insert(n);
    par[p[1]] = -1;
    used[p[1]] = 1;
    int cur = 1;
    int cur_v = p[1];
    s.erase(p[1]);
    cout << cur_v << "\n";
    while (cur < n) {
        cur_v = p[cur];
        while (cur + 1 < n && !used[p[cur + 1]])
            used[cur_v] = 1, cur++, par[p[cur]] = cur_v, cur_v = p[cur], s.erase(cur_v), used[cur_v] = 1;
        //cout << cur << ' ' << ' ' << p[cur + 1] << endl;
        int lst = *s.rbegin();
        s.erase(lst);
        //cout << '*' << lst << endl;
        par[lst] = cur_v;
        used[lst] = 1;
        cur++;
    }
    for (int i = 1; i <= n; i++)
        if (par[i] != -1)
            cout << i << ' ' << par[i] << "\n";
    return 0;
}
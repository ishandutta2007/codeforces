#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int N =  400;
const int M =  2e5;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> c(n * k);
    vector <vector <int> > mass(n);
    for(int i = 0; i < n * k; i++)
    {
        cin >> c[i];
        c[i]--;
        mass[c[i]].push_back(i);
    }
    vector <pair <int, int> > ans(n);
    int u = (n + k - 2) / (k - 1);
    vector <bool> used(n);
    for(int it = 0; it < k - 1; it++)
    {
        vector <pair <int, int> > to_sort;
        for(int i = 0; i < n; i++)
        {
            if(!used[i])
            {
                to_sort.push_back({mass[i][it + 1], i});
            }
        }
        sort(to_sort.begin(), to_sort.end());
        for(int i = 0; i < min(u, sz(to_sort)); i++)
        {
            int ind = to_sort[i].Y;
            ans[ind] = {mass[ind][it] + 1, mass[ind][it + 1] + 1};
            used[ind] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i].X << " " << ans[i].Y << "\n";
    }
    return 0;
}
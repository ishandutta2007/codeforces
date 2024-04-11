#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > edges;
int  solve(int L, int R)
{
    if(L > 1)
    {
        int k = solve(1, R - L + 1);
        edges.push_back({k, k + 1, L - 1});
        return k + 1;
    }
    int t = log2(R);
    if((1 << t) == R)
    {
        edges.push_back({1, 2, 1});
        for(int i = 3; i <= t + 2; i++)
        {
            edges.push_back({1, i, 1});
            for(int j = 2; j < i; j++)
            {
                edges.push_back({j, i, (1 << (j - 2))});
            }
        }
        return t + 2;
    }
    int k = 0;
    while(((1 << (k + 1))) <= R - 1)
    {
        k++;
    }
    solve(1, (1 << k));
    edges.push_back({1, k + 3, 1});
    for(int i = 0; i <= k; i++)
    {
        if((1 << i) & (R - 1))
        {
            edges.push_back({i + 2, k + 3, 1 + (((R - 1) >> (i + 1)) << (i + 1))});
        }
    }
    return k + 3;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int L, R;
    cin >> L >> R;
    int n = solve(L, R);
    cout << "YES\n";
    cout << n << " " << edges.size() << "\n";
    for(int i = 0; i < edges.size(); i++)
    {
        cout << edges[i][0] << " " << edges[i][1] << " " << edges[i][2] << "\n";
    }
	return 0;
}
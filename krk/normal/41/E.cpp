#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
bool forb[Maxn];
vector <int> neigh[Maxn];
vector <pair <int, int> > res;

void Add(int a, int b)
{
     neigh[a].push_back(b);
     neigh[b].push_back(a);
     res.push_back(make_pair(a, b));
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) {
        fill(forb, forb + n + 1, false);
        Add(i - 1, i);
        for (int l = 0; l < neigh[i - 1].size(); l++)
           forb[neigh[i - 1][l]] = true;
        for (int j = 1; j <= i - 2; j++)
           if (!forb[j]) {
                         Add(j, i);
                         for (int l = 0; l < neigh[j].size(); l++)
                            forb[neigh[j][l]] = true;
           }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
       cout << res[i].first << " " << res[i].second << endl;
    return 0;
}
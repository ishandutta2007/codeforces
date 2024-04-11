#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, t;
int a[Maxn][2], b[Maxn][2];
int m;
string word[Maxn];
int c[Maxn];
int d[Maxn][Maxn];
queue <int> Q;
vector <int> res[Maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
       cin >> a[i][0] >> b[i][0] >> a[i][1] >> b[i][1];
    cin >> m;
    for (int i = 0; i < m; i++) {
       cin >> word[i] >> c[i];
       Q.push(i);
    }
    while (!Q.empty())
       for (int j = 0; j < 2 && !Q.empty(); j++)
          for (int i = 0; i < n && !Q.empty(); i++) {
              int lft = t;
              while (lft && !Q.empty()) {
                    int q = Q.front(); Q.pop();
                    int ntime = max(1, c[q] - (a[i][j] + b[i][1 - j]) - d[i][q]);
                    if (lft >= ntime) {
                            res[i].push_back(q);
                            lft -= ntime;
                    } else {
                           d[i][q] += lft;
                           Q.push(q);
                           lft = 0;
                    }
              }
          }
    for (int i = 0; i < n; i++) {
        cout << res[i].size();
        for (int j = 0; j < res[i].size(); j++)
           cout << " " << word[res[i][j]];
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> unions[22222];
vector<int> sets[222];
vector<int> ii;
int uu[222];

int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    cin >> n;
    m = n * (n - 1) / 2;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int a;
            cin >> a;
            unions[i].push_back(a);
        }
        sort(unions[i].begin(), unions[i].end());
        if (m == 1)
        {
            cout << num - 1 << " ";
            for (int j = 0; j < num - 1; j++) cout << unions[i][j] << " "; cout << endl;
            cout << "1 " << unions[i][num - 1];
            return 0;
        }
    }
    int val = unions[0][0];
    for (int i = 0; i < m; i++)
    {
        bool fl = false;
        for (int j = 0; j < unions[i].size(); j++) if (unions[i][j] == val) fl = true;
        if (fl == true)
        {
            //cout << i << endl;
            for (int j = 0; j < unions[i].size(); j++) uu[unions[i][j]]++;
            ii.push_back(i);
        }
    }
   // cout << ii.size() << endl;
    for (int i = 0; i <= 200; i++)
    {
        if (uu[i] == n - 1) sets[0].push_back(i);
    }
    for (int i = 0; i < ii.size(); i++)
    {
        for (int j = 0; j < unions[ii[i]].size(); j++) if (uu[unions[ii[i]][j]] != n - 1) sets[i + 1].push_back(unions[ii[i]][j]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << sets[i].size() << " ";
        for (int j = 0; j < sets[i].size(); j++) cout << sets[i][j] << " ";
        cout << endl;
    }
    return 0;
}
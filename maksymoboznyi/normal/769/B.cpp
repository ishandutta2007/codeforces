#include <bits/stdc++.h>

using namespace std;

pair <int, int> a[1000];
bool used[1000];
int n;
vector <pair<int,int> > ans;
bool cmp(pair<int,int>a, pair<int,int> b)
{
    return a.first > b.first;
}
int main()
{
   cin >> n;
   for (int i = 0; i < n; i++)
   {
       cin >> a[i].first;
       a[i].second = i;
   }
   sort(a + 1, a + n, cmp);
   sort(a + 1, a + n, cmp);
   used[0] = true;
   for (int i = 0; i < n; i++)
   {
       int k = 0, p = i + 1;
       while (k < a[i].first && p < n)
       {
           if (!used[p])
           {
               used[p] = true;
               k++;
               ans.push_back({a[i].second+1,a[p].second + 1});
           }
           p++;
       }
   }
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            cout << -1;
            return 0;
        }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;
   return 0;
}
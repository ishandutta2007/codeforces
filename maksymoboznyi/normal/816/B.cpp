#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

struct cell
{
    int it, val;
};
vector<cell> a;
bool used[200005];
int s[200005];
int n, k ,q, lv;
bool cmp(cell a, cell b)
{
    if (a.val != b.val)
        return a.val < b.val;
    return a.it > b.it;
}
int main()
{
    cin >> n >> k >> q;
    int yy, xx;
    for (int i = 1; i <= n; i++)
    {
        cin >> xx >> yy;
        a.pb({0, xx});
        a.pb({1, yy+1});
    }
    sort(a.begin(), a.end(), cmp);
    lv = 0;
    int cur = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].it == 0)
        {
            cur++;
            if (cur == k)
                lv = a[i].val;
        }else
        {
            cur--;
            //cout << lv << endl;
         //   cout << a[i].val<<endl;
            if (cur == k -1)
            for (int j = lv; j < a[i].val; j++)
                used[j] = true;
        }
    }
    s[0] = 0;
    for (int i = 1; i <= 200000; i++)
        s[i] = s[i-1] + used[i];
    int u, v;
    for (int i = 0; i < q; i++)
    {
        cin >> u >> v;
        cout << s[v] - s[u-1] << endl;
    }
    return 0;
}
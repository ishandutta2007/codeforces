#include <bits/stdc++.h>

using namespace std;
int a[10000];
int n, sum;
struct cell
{
    int l, r;
};
vector <cell> ans;
int s[101];
void func(int l)
{
    if (l == n)
    {
        cout << "YES"<<endl;
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].l << ' ' << ans[i].r << endl;
        exit(0);
    }

    for (int i = l + 1; i <= n; i++)
        if (s[i] - s[l] != 0)
        {
            ans.push_back({l + 1, i});
            func(i);
            ans.pop_back();
        }
}
int main()
{
    bool t = true;
    bool r = false;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
            t = false;
        if (a[i] == 0)
            r = true;
        sum += a[i];
    }
    if (t)
    {
        cout << "NO";
        return 0;
    }
    s[1] = a[1];
    for (int i = 1; i <= n; i++)
        s[i] = a[i] + s[i-1];
    func(0);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &elem : a)
        cin >> elem;
    sort(a.begin(), a.end());
    for (int l = 0, r = 2; r < a.size(); l++, r++)
        if (a[r] - a[l] == 2)
        {
            cout << "NO";
            return 0;
        }
    for (auto elem: a)
        if (elem == 1 || elem == n)
        {
            cout << "NO";
            return 0;
        }
    cout << "YES";

    return 0;
}
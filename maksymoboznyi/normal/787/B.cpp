#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n, m, k;
struct cell
{
    int val, zn;
};
cell a[100000];
bool cmp(cell a, cell b)
{
    return a.val < b.val;
}
int size;
int main()
{
    int x;
    cin >> n >> m;
    for (int ii = 0; ii < m; ii++)
    {
        cin >> k;
        size = 0;
        for (int i = 0; i < k; i++)
        {
            cin >> x;
            if (x < 0)
                a[size].zn = -1;
            else
                a[size].zn = 1;
            a[size].val = abs(x);
            size++;
        }
        bool r = false;
        sort(a, a + size, cmp);
        for (int i = 0; i < size - 1; i++)
            if (a[i].val == a[i+1].val && a[i].zn != a[i+1].zn)
            {
                r = true;
                break;
            }
        if (!r)
        {
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
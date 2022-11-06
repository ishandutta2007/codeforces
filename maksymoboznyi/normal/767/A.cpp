#include <bits/stdc++.h>

using namespace std;
struct  cell
{
    int val, num;
};
cell a[100005];
int n;
bool cmp(cell a, cell b)
{
    return a.val > b.val;
}
int main()
{
    cin >> n;
    for (int i= 0; i < n; i++)
    {
        cin >> a[i].val;
        a[i].num = i;
    }
    sort(a, a + n, cmp);
    int ma = 0;
    int i = -1;
    for (int i = 0; i < a[0].num; i++)
        cout << endl;
    a[n].num = 9999999999;
    while (i < n)
    {
        //cout << i <<' ' << ma<<endl;
        while (a[i+1].num <= a[ma].num && i + 1 < n)
        {
            i++;
            cout << a[i].val << ' ';
        }
        if (i > n - 2)
            break;
        for (int j = a[ma].num; j < a[i+1].num; j++)
            cout << endl;
        ma = i + 1;
    }
    //if (a[n-1].num )
    return 0;
}
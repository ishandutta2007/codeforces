#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200005;

int n, k, a[N], pt = 0;
vector<int> cur, ans, ret;
bool chk[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", a + i);
        cur.push_back(a[i]);
        chk[a[i]] = true;
        while (!cur.empty() && cur.back() == pt + 1)
        {
            cur.pop_back();
            ++pt;
        }
    }
    while (!cur.empty())
    {
        ++pt;
        while (pt < cur.back())
            if (chk[pt])
            {
                printf("-1");
                return 0;
            }
            else ans.push_back(pt++);
        while (!ans.empty())
        {
            ret.push_back(ans.back());
            ans.pop_back();
        }
        cur.pop_back();
    }
    for (int i = 1; i <= k; i++)
        printf("%d ", a[i]);
    for (int v : ret)
        printf("%d ", v);
    for (int i = n; i > pt; i--)
        printf("%d ", i);
}
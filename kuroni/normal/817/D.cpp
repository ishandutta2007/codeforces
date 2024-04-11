#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <int> maxst, minst;
long long f_max[1000005], f_min[1000005], ans = 0;
int n, a[1000005], i, l_max[1000005], l_min[1000005];

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (i = 1; i <= n; i++)
    {
        while (!maxst.empty() && a[maxst.back()] < a[i])
            maxst.pop_back();
        if (maxst.empty())
            l_max[i] = 1;
        else l_max[i] = maxst.back() + 1;
        maxst.push_back(i);
        while (!minst.empty() && a[minst.back()] > a[i])
            minst.pop_back();
        if (minst.empty())
            l_min[i] = 1;
        else l_min[i] = minst.back() + 1;
        minst.push_back(i);
    }
    f_max[0] = f_min[0] = 0;
    for (i = 1; i <= n; i++)
    {
        f_max[i] = f_max[l_max[i] - 1] + (long long) a[i] * (i - l_max[i] + 1);
        f_min[i] = f_min[l_min[i] - 1] + (long long) a[i] * (i - l_min[i] + 1);
        ans += f_max[i] - f_min[i];
    }
    printf("%I64d", ans);
}
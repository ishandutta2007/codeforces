#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long p;
int k;
vector<int> ans;

int main()
{
    scanf("%I64d%d", &p, &k);
    while (p != 0)
    {
        int cur = ((p % k) + k) % k;
        ans.push_back(cur);
        (p -= cur) /= k;
        p = -p;
    }
    printf("%d\n", ans.size());
    for (int v : ans)
        printf("%d ", v);
}
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map <long long, int> whole, suff;
int n, a[100005], i;
long long sum = 0, part_sum = 0;

int main()
{
    suff[0] = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        whole[a[i]]++;
        sum += a[i];
    }
    if (sum % 2 == 1)
    {
        printf("NO");
        return 0;
    }
    for (i = 1; i <= n; i++)
    {
        suff[a[i]]++;
        part_sum += a[i];
        if (part_sum >= sum / 2 && (suff[part_sum - sum/2] > 0))
        {
            printf("YES");
            return 0;
        }
        else if (part_sum < sum / 2 && (whole[sum / 2 - part_sum] > suff[sum / 2 - part_sum]))
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
/*
    author:     MarX
    school:     UH
*/

#include <stdio.h>

using namespace std;

int total[3010];
int next[3010];

int main()
{
    int trees, amount;
    scanf("%d%d",&trees,&amount);
    int a,b;
    for (int i = 0; i < trees; ++i)
    {
        scanf("%d%d",&a,&b);
        total[a] += b;
        next[a + 1] += b;
    }   
    int t = 0;

    for (int i = 1; i < 3010; ++i)
    {
        if (next[i] <= amount)
        {
            t += next[i];
            int cur_amount = amount - next[i];
            if (total[i] <= cur_amount)
            {
                t += total[i];
                next[i + 1] -= total[i];
            }
            else
            {
                t += cur_amount;
                next[i + 1] -= cur_amount;
            }
        }
        else
        {
            t += amount;
        }
    }
    printf("%d\n",t);
    return 0;
}
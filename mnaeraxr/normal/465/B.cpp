/*
    author:     MarX
    school:     UH
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; scanf("%d",&n);
    int c = 0; bool ii = false;
    int tot = 0;
    for (int i = 0; i < n; ++i)
    {
        int v; scanf("%d",&v);
        if (v == 1)
        {
            tot++;
            c++;
            ii = true;
        }
        else
        {
            if (ii)
            {
                c++;
                ii = false;
            }
        }
    }
    if (ii)
    {
        c++;
        ii = false;
    }
    c--;

    if (tot == 0)
        printf("0\n");
    else
        printf("%d\n", c);
    
    return 0;
}
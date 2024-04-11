/*
    author:     MarX
    school:     UH
*/

#include <bits/stdc++.h>

using namespace std;

char W[1000 + 10];
int N[1000 + 10];

int main()
{
    int n, m;
    scanf("%d%d%s",&n,&m,W);
    for (int i = 0; i < n; ++i)
        (N[i] = W[i] - 'a');

    bool fixed = false;
    for (int i = n - 1; i >= 0; --i)
    {
        while (true)
        {
            N[i]++;
            //cout << N[i] << endl;
            if (N[i] == m)
                break;
            if (i - 1 >= 0 && N[i] == N[i - 1])
                continue;
            if (i - 2 >= 0 && N[i] == N[i - 2])
                continue;

            fixed = true;

            for (int j = i + 1; j < n; ++j)
            {
                N[j] = -1;
                while (true)
                {
                    N[j]++;
                    if (j - 1 >= 0 && N[j] == N[j - 1])
                        continue;
                    if (j - 2 >= 0 && N[j] == N[j - 2])
                        continue;
                    break;
                }
            }
            break;
        }
        if (fixed)
            break;
    }
    if (!fixed)
        printf("NO\n");
    else
    {
        for (int i = 0; i < n; ++i)
            printf("%c",'a' + N[i]);
        printf("\n");
    }
    //system("pause");
    return 0;
}
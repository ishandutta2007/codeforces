/*


*/

/*
    author:     MarX & ArielxX
    school:     UH
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <complex>
#include <cmath>

using namespace std;

int P[100100];
int I[100100];

int main()
{
    int total,k,p;
    scanf("%d%d%d",&total,&k,&p);
    int tot_par = 0;
    int tot_impar = 0;
    int value;
    for (int i = 0; i < total; ++i)
    {
        scanf("%d",&value);
        if (value % 2 == 0)
        {
            P[tot_par] = value;
            tot_par++;
        }
        else
        {
            I[tot_impar] = value;
            tot_impar++;
        }
    }
    int ni = k - p;
    if (tot_impar >= ni && (tot_impar - ni)% 2 == 0 
        && (tot_par + (tot_impar - ni)/2) >= p)
    {
        printf("YES\n");
        if (p == 0)
        {
            for (int i = 0; i < ni - 1; ++i)
                printf("1 %d\n",I[i]);
            printf("%d",total - (ni - 1));
            for (int i = ni - 1; i < tot_impar; ++i)
                printf(" %d",I[i]);
            for (int i = 0; i < tot_par; ++i)
                printf(" %d",P[i]);
            printf("\n");           
        }
        else
        {
            int p_imp = 0;
            int i_imp = 0;
            for (int i = 0; i < ni; ++i){
                printf("1 %d\n",I[i]); i_imp++;}

            for (int i = 0; i < p - 1 && i < tot_par; ++i){
                printf("1 %d\n", P[i]); p_imp++;}

            for (int i = 0; i < p - tot_par - 1; ++i)
            {
                printf("2 %d %d\n",I[ni + 2*i],I[ni + 2*i + 1]); i_imp+=2;
            }

            if (total - (p_imp + i_imp) > 0)
            {
                printf("%d",total - (p_imp + i_imp));
                for (int i = i_imp; i < tot_impar; ++i)
                    printf(" %d",I[i]);
                for (int i = p_imp; i < tot_par; ++i)
                    printf(" %d", P[i]);
                printf("\n");
            }
        }
    }
    else
    {
        printf("NO\n");
    }
    //system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==1) printf("-1\n");
        else
        {
            printf("2");
            while(--n) printf("9");
            printf("\n");
        }
    }
    return 0;
}
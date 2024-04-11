#include <cstdio>
int main()
{
    int k,c=3;
    scanf("%d",&k);
    if(k % 2 == 0)
	{
        printf("NO\n");
        return 0;
    }
    int d = (((k - 1) / 2) * (k + 1) + 1) * 2;
    printf("YES\n%d %d\n1 2\n",d,d * k / 2);
    for(int i = 0; i < (k - 1) / 2; i ++)
	{
        int cc = c ++, cd = c ++;
        printf("%d %d\n",1,cc);
        printf("%d %d\n",1,cd);
        for(int j = 0; j < k - 1; j ++)
		{
            int ce = c + j;
            printf("%d %d\n",cc,ce);
            printf("%d %d\n",ce,cd);
            for(int jj = j + 1; jj < k - 1; jj ++)
                printf("%d %d\n",c + j, c + jj);
        }
        c += (k - 1);
    }
    for(int i = 0; i < (k - 1) / 2; i ++)
	{
        int cc = c ++, cd = c ++;
        printf("%d %d\n",2,cc);
        printf("%d %d\n",2,cd);
        for(int j = 0; j < k - 1; j ++)
		{
            int ce = c + j;
            printf("%d %d\n",cc,ce);
            printf("%d %d\n",ce,cd);
            for(int jj = j + 1; jj < k - 1; jj ++) 
                printf("%d %d\n",c + j,c + jj);
            
        }
        c += (k - 1);
    }
    return 0;
}
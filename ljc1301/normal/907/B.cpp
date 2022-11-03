#include <cstdio>
char ma[15][15];
int main()
{
    int i,j,x,y;
    bool flag=false;
    for(i=0;i<9;i++)
        for(j=0;j<9;j+=3)
            scanf("%s",ma[i]+j);
    scanf("%d%d",&x,&y);
    x=(x-1)%3; y=(y-1)%3;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(ma[i+x*3][j+y*3]=='.')
            {
                flag=true;
                ma[i+x*3][j+y*3]='!';
            }
    if(!flag)
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
                if(ma[i][j]=='.')
                    ma[i][j]='!';
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%c",ma[i][j]);
            if(j%3==2)
                printf(" ");
        }
        if(i%3==2) printf("\n");
        printf("\n");
    }
    return 0;
}
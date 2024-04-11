#include<cstdio>
#include<cstring>
#define N 1000006
int n,k;
char c[N];
int main()
{
    while(scanf("%d%d",&n,&k)==2)
    {
        scanf("%s",c+1);
        for(int i=1;i<=n&&k;i++)
        if(c[i]=='4'&&c[i+1]=='7')
        {
            if(i&1)
            {
                if(c[i+2]=='7')
                {if(k&1)c[i+1]='4';k=0;}
                else c[i+1]='4',k--;
            }
            else c[i]='7',k--,i-=2;
        }
        puts(c+1);
    }
}
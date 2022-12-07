#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char str[10];
int type[20],r[20],b[20];
int f[1<<16][200],red[1<<16],blue[1<<16];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s%d%d",str,&r[i],&b[i]);
        if(str[0]=='R') type[i]=1;
        else type[i]=2;
    }
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<200;j++)
            f[i][j]=-1000000010;
    f[0][0]=0;
    for(int S=1;S<(1<<n);S++)
    {
        for(int k=0;k<n;k++)
            if(S&(1<<k))
            {
                int pre=S^(1<<k);
                red[S]=red[pre],blue[S]=blue[pre];
                if(type[k]==1) red[S]++;
                else blue[S]++;
                int saver=r[k]-max(r[k]-red[pre],0);
                int saveb=b[k]-max(b[k]-blue[pre],0);
                for(int o=0;o<200-saver;o++)
                    f[S][o+saver]=max(f[S][o+saver],f[pre][o]+saveb);
            }
    }
    int needr=0,needb=0;
    for(int i=0;i<n;i++)
        needr+=r[i],needb+=b[i];
    int ans=1000000010;
    for(int i=0;i<200;i++)
        ans=min(ans,max(needr-i,needb-f[(1<<n)-1][i]));
    printf("%d\n",ans+n);
    return 0;
}
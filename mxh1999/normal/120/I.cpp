//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 200010
const int num[10][7]=
{
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};
int b[10][10];
char s[maxn];
int a[maxn];
int n,m;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    for (int i=0;i<=9;i++)
        for (int j=0;j<=9;j++)
            for (int k=0;k<=6;k++)
                b[i][j]+=num[i][k]&num[j][k];
    scanf("%s",&s);
    n=strlen(s);
    for (int i=1;i<=n;i++)  a[i]=s[i-1]-'0';
    m=n>>1;
    int now=0;
    for (int i=n;i>=1;i--)
    {
        int tmp,tmp2;
        if (i>m)    tmp=a[i-m];else tmp=a[i+m];
        for (int j=a[i]+1;j<=9;j++)
        if (now+b[j][tmp]-b[a[i]][tmp]>0)
        {
            now+=b[j][tmp]-b[a[i]][tmp];
            a[i]=j;
            for (int k=i+1;k<=n;k++)
            {
                if (k>m)    tmp2=a[k-m];else tmp2=a[k+m];
                for (int kk=0;kk<=a[k];kk++)
                if (now+b[kk][tmp2]-b[a[k]][tmp2]>0)
                {
                    now+=b[kk][tmp2]-b[a[k]][tmp2];
                    a[k]=kk;
                    break;
                }
            }
            for (int k=1;k<=n;k++)
                printf("%d",a[k]);
            printf("\n");
            return 0;
        }
        now+=b[8][tmp]-b[a[i]][tmp];
        a[i]=8;
    }
    printf("-1\n");
    return 0;
}
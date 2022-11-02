//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 1010
int n;
int xg[maxn],sg[maxn];
int kt1[266],kt2[266],hzh1[266],hzh2[266],myw;

struct Str
{
    char s[21],l;
}   a[maxn],b[maxn];
bool cmp(const Str &x,const Str &y)
{
    for (int i=1;i<=x.l || i<=y.l;i++)
        if (x.s[i]!=y.s[i]) return x.s[i]<y.s[i];
    return 0;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",a[i].s+1);
        a[i].l=strlen(a[i].s+1);
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%s",b[i].s+1);
        b[i].l=strlen(b[i].s+1);
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=n;i++)  hzh1[a[i].s[1]]++;
    for (int i=1;i<=n;i++)  hzh2[b[i].s[1]]++;
    for (int i=1;i<=n;i++)
    if (b[i].s[1]!=b[i-1].s[1])
        kt2[b[i].s[1]]=i;
    kt2['Z'+1]=n+1;
    myw='A';
    while (hzh2[myw]<=hzh1[myw] && myw<='Z')    myw++;
    for (int j=1;j<=n;j++)
    {
        int i=a[j].s[1];
        if (hzh1[i]>hzh2[i] && myw<i)
        {
            xg[j]=kt2[myw]++;
            hzh2[myw]--,hzh1[i]--;
            while (hzh2[myw]<=hzh1[myw] && myw<='Z')    myw++;
        }   else
        if (hzh2[i])
        {
            xg[j]=kt2[i]++;
            hzh1[i]--;
            hzh2[i]--;
        }   else 
        {
            xg[j]=kt2[myw]++;
            hzh2[myw]--;
            hzh1[i]--;
            while (hzh2[myw]<=hzh1[myw] && myw<='Z')    myw++;
        }
    }
    for (int i=1;i<n;i++)
        printf("%s %s, ",a[i].s+1,b[xg[i]].s+1);
    printf("%s %s\n",a[n].s+1,b[xg[n]].s+1);
    return 0;
}
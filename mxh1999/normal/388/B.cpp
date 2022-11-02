#include<cstdio>
#include<iostream>
using namespace std;

int tot=4,tot1,next;
int last=3;
int map[151][151];
int f[151],dep[151];
int n,x,y;

void addedge(int x,int y)
{
    map[x][y]=true;
    map[y][x]=true;
    f[x]+=f[y];
    dep[x]=dep[y]+1;
}
int main()
{
    addedge(1,3);
    addedge(1,4);
    f[3]=1;
    f[4]=1;
    for (int i=1;i<=10;i++)
    {
        for (int j=0;j<i;j++)
            addedge(tot+j+1,last+j);
        addedge(tot+i+1,tot);
        addedge(tot+i+1,tot-1);
        addedge(tot+i+2,tot);
        addedge(tot+i+2,tot-1);
        last=tot+1;
        tot+=i+2;
    }
    f[2]=1;
    tot1=150;
    addedge(150,2);addedge(149,2);addedge(148,2);addedge(147,2);
    tot1=147;
    for (int i=0;i<=18;i+=2)
    {
        for (int j=0;j<=3;j++)
            for (int k=1;k<=4;k++)
                addedge(tot1-k,tot1+j);
        tot1-=4;
    }
    addedge(106,110);addedge(106,109);addedge(106,108);addedge(106,107);
    tot1=105;
    addedge(105,147);
    for (int i=2;i<=22;i+=2)
    {
        tot1--;
        addedge(tot1,tot1+1);
    }
    //printf("%d\n",tot1);
    tot1--;
    addedge(tot1,130);addedge(tot1,129);
    for (int i=12;i<=22;i+=2)
    {
        tot1--;
        addedge(tot1,tot1+1);
    }
    //printf("%d\n",tot1);
    scanf("%d",&n);
    int num=0;
    int ans=0;
    while (n)
    {
        if (n&1)
        {
            x=num/11;
            y=num%11;
            if (x==0)
            {
                map[95][last+y]=true;
                map[last+y][95]=true;
                ans+=f[95]*f[last+y];
            }
            if (x==1)
            {
                map[88][last+y]=true;
                map[last+y][88]=true;
                ans+=f[88]*f[last+y];
            }
            if (x==2)
            {
                map[106][last+y]=true;
                map[last+y][106]=true;
                ans+=f[106]*f[last+y];
            }
        }
        num++;
        n>>=1;
    }
    //printf("%d\n",ans);
    //return 0;
    printf("%d\n",150);
    for (int i=1;i<=150;i++)
    {
        for (int j=1;j<=150;j++)
        if (map[i][j])  printf("Y");else printf("N");
        printf("\n");
    }
    return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            char ch,ch1=(i+j)%2==0?'B':'W';
            ch=getchar();
            while (ch==' ' || ch=='\n') ch=getchar();
            if (ch=='-') printf("%c",ch);else printf("%c",ch1);
        }
        printf("\n");
    }
    return 0;
}
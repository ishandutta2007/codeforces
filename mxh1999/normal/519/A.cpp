//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int main()
{
    for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++)
        {
            char ch=getchar();
            while (ch!='K' && ch!='Q' && ch!='R' && ch!='B' && ch!='N' && ch!='P' &&
                    ch!='k' && ch!='q' && ch!='r' && ch!='b' && ch!='n' && ch!='p' && ch!='.')
                    ch=getchar();
            if (ch=='K')    n+=0;else
            if (ch=='Q')    n+=9;else
            if (ch=='R')    n+=5;else
            if (ch=='B')    n+=3;else
            if (ch=='N')    n+=3;else
            if (ch=='P')    n+=1;else
            if (ch=='k')    m+=0;else
            if (ch=='q')    m+=9;else
            if (ch=='r')    m+=5;else
            if (ch=='b')    m+=3;else
            if (ch=='n')    m+=3;else
            if (ch=='p')    m+=1;
        }
    if (n>m)    printf("White\n");
    if (m>n)    printf("Black\n");
    if (n==m)   printf("Draw\n");
    return 0;
}
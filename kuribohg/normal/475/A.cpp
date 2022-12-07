#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,a[5];
int main()
{
    scanf("%d",&n);
    puts("+------------------------+");
    a[1]=(n+1)/3;a[2]=n/3;
    if(n==1) a[1]=1;
    else if(n==2) a[1]=a[2]=1;
    putchar('|');
    for(int i=1;i<=11;i++)
        if(i<=a[1]) printf("O.");
        else printf("#.");
    puts("|D|)");
    putchar('|');
    for(int i=1;i<=11;i++)
        if(i<=a[2]) printf("O.");
        else printf("#.");
    puts("|.|");
    if(n>=3) puts("|O.......................|");
    else puts("|#.......................|");
    a[4]=(n-1)/3;
    putchar('|');
    for(int i=1;i<=11;i++)
        if(i<=a[4]) printf("O.");
        else printf("#.");
    puts("|.|)");
    puts("+------------------------+");
    return 0;
}
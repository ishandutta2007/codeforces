#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int n;
void getn()
{
    char c=getchar();
    while(c>='0'&&c<='9') n=((n*10)+c-'0')%4,c=getchar();
}
int main()
{
    getn();
    if(n==1) puts("0");
    else if(n==2) puts("0");
    else if(n==3) puts("0");
    else puts("4");
    return 0;
}
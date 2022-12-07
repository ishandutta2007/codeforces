#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",min(min(2*(a+b),2*(b+c)),min(2*(a+c),a+b+c)));
    return 0;
}
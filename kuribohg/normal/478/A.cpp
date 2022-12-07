#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int a[10],s;
int main()
{
    for(int i=1;i<=5;i++) scanf("%d",&a[i]),s+=a[i];
    if(s%5!=0||s==0) puts("-1");
    else printf("%d\n",s/5);
    return 0;
}
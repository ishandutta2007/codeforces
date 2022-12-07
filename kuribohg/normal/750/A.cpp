#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,sum;
int main()
{
    scanf("%d%d",&n,&k);
    int x=240-k;
    for(int i=1;i<=n;i++)
        if(x>=5*i) sum++,x-=5*i;
    printf("%d\n",sum);
    return 0;
}
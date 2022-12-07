#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,sum,sum2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=10000;i++)
    {
        sum2+=i,sum+=sum2;
        if(sum>n) {printf("%d\n",i-1);return 0;}
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1010;
int n,k,N;
int main()
{
    scanf("%d%d",&n,&k);
    N=n*(n-1)/2;
    if(N<k*n) {puts("-1");return 0;}
    printf("%d\n",k*n);
    for(int step=1;step<=k;step++)
    {
        for(int i=1;i<=n;i++)
            printf("%d %d\n",i,(i+step-1)%n+1);
    }
    return 0;
}
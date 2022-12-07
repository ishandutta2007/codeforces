#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,a[10010],sum;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) sum+=a[i];
    if(sum+10*(n-1)>m) {puts("-1");return 0;}
    printf("%d\n",(m-sum)/5);
    return 0;
}
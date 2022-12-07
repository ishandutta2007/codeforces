#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000010;
int n,m,a[MAXN],now;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++) scanf("%d",&a[i]);
    now=1;
    while(now!=n)
    {
        if(now==m) {puts("YES");return 0;}
        now=now+a[now];
    }
    if(now==m) {puts("YES");return 0;}
    puts("NO");
    return 0;
}
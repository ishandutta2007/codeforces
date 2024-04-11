#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k,x;
bool used[200];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        while(k--) scanf("%d",&x),used[x]=true;
    }
    for(int i=1;i<=m;i++)
        if(!used[i]) {puts("NO");return 0;}
    puts("YES");
    return 0;
}
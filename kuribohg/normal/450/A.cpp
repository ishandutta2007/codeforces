#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,a[101],ans;
queue<int> q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) q.push(i);
    while(!q.empty())
    {
        int x=q.front();
        ans=x;
        q.pop();
        a[x]-=m;
        if(a[x]>0) q.push(x);
    }
    printf("%d\n",ans);
    return 0;
}
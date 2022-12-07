#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000010;
struct Node{int a,b;}p[MAXN];
int n,t;
bool cmp(const Node &i,const Node &j)
{
    return i.a==j.a?i.b<j.b:i.a<j.a;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i].a,&p[i].b);
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(p[i].b<t) t=p[i].a;
        else t=p[i].b;
    }
    printf("%d\n",t);
    return 0;
}
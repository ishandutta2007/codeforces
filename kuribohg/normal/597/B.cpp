#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
const int MAXN=500010;
int n,cur,ans;
pair<int,int> P[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&P[i].second,&P[i].first);
    sort(P+1,P+n+1);
    for(int i=1;i<=n;i++)
        if(P[i].second>cur) cur=P[i].first,ans++;
    printf("%d\n",ans);
    return 0;
}
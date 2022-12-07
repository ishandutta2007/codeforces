#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<cstdlib>
#include<map>
using namespace std;
const int MAXN=200010;
int n,Q,x[MAXN],sub,Len;
pair<int,int> P[MAXN];
map<int,int> id;
int Next(int sub,int Len)
{
    int x=lower_bound(P+1,P+n+1,make_pair(P[sub].first+Len+1,-1))-P-1;
    if(x==sub) x=lower_bound(P+1,P+n+1,make_pair(P[sub].first-Len,-1))-P;
    return x;
}
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]),P[i]=make_pair(x[i],i);
    sort(P+1,P+n+1);
    for(int i=1;i<=n;i++) id[P[i].first]=i;
    while(Q--)
    {
        scanf("%d%d",&sub,&Len);
        sub=id[x[sub]];
        while(Next(sub,Len)!=sub)
        {
            int x=Next(sub,Len);
            int nLen=Len-abs(P[x].first-P[sub].first);
            if(Next(x,nLen)==sub) Len%=2*(P[x].first-P[sub].first);
            else sub=x,Len=nLen;
        }
        printf("%d\n",P[sub].second);
    }
    return 0;
}